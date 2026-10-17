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

int N = 128, M = 150, K = 3, T, si, sj;
vector<pii> g(M);
map<pii, int> magic_count;

void input() {
  cin >> N >> M >> K >> T;
  cin >> si >> sj;
  g.resize(M);
  rep(i, 0, M) {
    int gi, gj;
    cin >> gi >> gj;
    g[i] = {gi, gj};
  }
}

void walk(int gi, int gj) {
  while (si < gi) {
    cout << "D\n";
    si++;
  }
  while (si > gi) {
    cout << "U\n";
    si--;
  }
  while (sj < gj) {
    cout << "R\n";
    sj++;
  }
  while (sj > gj) {
    cout << "L\n";
    sj--;
  }
}

pii midpoint(pii a, pii b) {
  return {(a.first + b.first) / 2, (a.second + b.second) / 2};
}

bool is_inside(pii p) {
  return 0 <= p.first and p.first < N and 0 <= p.second and p.second < N;
}

int dist(pii a, pii b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void jump(pii q) {
  cout << "J " << q.first << ' ' << q.second << '\n';
  magic_count[q]--;
  magic_count[{si, sj}]++;
  si = 2 * q.first - si;
  sj = 2 * q.second - sj;
}

bool try_jump(pii target) {
  pii cur = {si, sj};
  int before = dist(cur, target);
  pii best_q = {-1, -1};
  int best_dist = before;
  for (auto [q, count] : magic_count) {
    if (count <= 0) continue;
    pii dest = {2 * q.first - si, 2 * q.second - sj};
    if (!is_inside(dest)) continue;
    int d = dist(dest, target);
    if (d < best_dist) {
      best_dist = d;
      best_q = q;
    }
  }
  if (best_q.first == -1) return false;
  jump(best_q);
  return true;
}

void solve() {
  vector<pii> magic = {midpoint({si, sj}, g[0]), midpoint(g[0], g[1]), midpoint(g[1], g[2])};
  for (auto [a, b] : magic) {
    cout << a << ' ' << b << '\n';
    magic_count[{a, b}]++;
  }
  rep(i, 0, 3) {
    pii target = g[i];
    pii q = magic[i];
    pii dest = {2 * q.first - si, 2 * q.second - sj};
    if (magic_count[q] > 0 and is_inside(dest)) {
      jump(q);
    }
    walk(target.first, target.second);
  }
  rep(i, 3, M) {
    try_jump(g[i]);
    walk(g[i].first, g[i].second);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}
