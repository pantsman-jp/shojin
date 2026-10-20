#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define YN(tf) cout << (tf ? "YES\n" : "NO\n")
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
template <typename T, typename U>
inline bool chmax(T& x, const U& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T, typename U>
inline bool chmin(T& x, const U& y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T>
inline T lcm(T a, T b) {
  return (a / std::gcd(a, b)) * b;
}
template <typename T>
inline T divceil(T a, T b) {
  return (a + b - 1) / b;
}
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using rpq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);

int N, M, K, T, si, sj;
vector<pii> g;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Result {
  int score;
  vector<string> ops;
};

void input() {
  cin >> N >> M >> K >> T;
  cin >> si >> sj;
  g.resize(M);
  rep(i, 0, M) {
    cin >> g[i].first >> g[i].second;
  }
}

int dist(pii a, pii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

bool is_inside(pii p) {
  return 0 <= p.first && p.first < N &&
         0 <= p.second && p.second < N;
}

pii midpoint(pii a, pii b) {
  return {(a.first + b.first) / 2,
          (a.second + b.second) / 2};
}

void walk(pii target, pii& cur, vector<string>& ops) {
  while (cur.first < target.first) {
    ops.push_back("D");
    cur.first++;
  }
  while (cur.first > target.first) {
    ops.push_back("U");
    cur.first--;
  }
  while (cur.second < target.second) {
    ops.push_back("R");
    cur.second++;
  }
  while (cur.second > target.second) {
    ops.push_back("L");
    cur.second--;
  }
}

void jump(pii q, pii& cur, map<pii, int>& magic_count,
          vector<string>& ops) {
  ops.push_back("J " + to_string(q.first) + " " +
                to_string(q.second));
  magic_count[q]--;
  magic_count[cur]++;
  cur = {2 * q.first - cur.first,
         2 * q.second - cur.second};
}

Result simulate(const vector<pii>& magic) {
  pii cur = {si, sj};
  map<pii, int> magic_count;
  for (pii p : magic) {
    magic_count[p]++;
  }
  vector<string> ops;
  for (pii target : g) {
    int before = dist(cur, target);
    int best_dist = before;
    pii best_q = {-1, -1};
    for (auto [q, count] : magic_count) {
      if (count <= 0) continue;
      pii dest = {2 * q.first - cur.first,
                  2 * q.second - cur.second};
      if (!is_inside(dest)) continue;
      int d = dist(dest, target);
      if (d < best_dist) {
        best_dist = d;
        best_q = q;
      }
    }
    if (best_q.first != -1) {
      jump(best_q, cur, magic_count, ops);
    }
    walk(target, cur, ops);
  }
  return {(int)ops.size() <= T ? T - (int)ops.size() : -inf,
          move(ops)};
}

vector<pii> neighbor(const vector<pii>& magic) {
  vector<pii> next = magic;
  int idx = uniform_int_distribution<int>(0, K - 1)(rng);
  if (uniform_int_distribution<int>(0, 99)(rng) < 15) {
    next[idx] = {
        uniform_int_distribution<int>(0, N - 1)(rng),
        uniform_int_distribution<int>(0, N - 1)(rng)};
  } else {
    int d = uniform_int_distribution<int>(0, 3)(rng);
    if (d == 0) next[idx].first++;
    if (d == 1) next[idx].first--;
    if (d == 2) next[idx].second++;
    if (d == 3) next[idx].second--;
    next[idx].first = clamp(next[idx].first, 0, N - 1);
    next[idx].second = clamp(next[idx].second, 0, N - 1);
  }
  return next;
}

void solve() {
  vector<pii> current(K);
  current[0] = midpoint({si, sj}, g[0]);
  current[1] = midpoint(g[0], g[1]);
  current[2] = midpoint(g[1], g[2]);

  Result current_result = simulate(current);
  vector<pii> best = current;
  Result best_result = current_result;

  const double time_limit = 1.85;
  const double start_temp = 2.0;
  const double end_temp = 0.1;
  auto start = chrono::steady_clock::now();

  while (true) {
    double elapsed = chrono::duration<double>(
                         chrono::steady_clock::now() - start)
                         .count();
    if (elapsed >= time_limit) break;

    double progress = elapsed / time_limit;
    double temp = start_temp *
                  pow(end_temp / start_temp, progress);

    vector<pii> next = neighbor(current);
    Result next_result = simulate(next);

    int delta = next_result.score - current_result.score;
    if (delta >= 0 ||
        uniform_real_distribution<double>(0.0, 1.0)(rng) <
            exp((double)delta / temp)) {
      current = move(next);
      current_result = move(next_result);
    }

    if (current_result.score > best_result.score) {
      best = current;
      best_result = current_result;
    }
  }

  for (pii p : best) {
    cout << p.first << ' ' << p.second << '\n';
  }
  for (const string& op : best_result.ops) {
    cout << op << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}