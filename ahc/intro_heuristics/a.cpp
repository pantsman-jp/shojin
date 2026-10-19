// Template: https://github.com/pantsman-jp/shojin/blob/main/ahc/template/main.cpp
// License: CC0 1.0 Universal
// https://github.com/pantsman-jp/shojin/blob/main/LICENSE
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
using pll = pair<ll, ll>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randrange(int l, int r) {
  return uniform_int_distribution<int>(l, r - 1)(rng);
}

double randdouble() { return uniform_real_distribution<double>(0.0, 1.0)(rng); }

using Clock = chrono::steady_clock;
using Timer = chrono::time_point<Clock>;

struct TimeKeeper {
  Timer start;
  double time_limit;
  explicit TimeKeeper(double time_limit_ms)
      : start(Clock::now()), time_limit(time_limit_ms) {}
  double elapsed() const {
    return chrono::duration<double, milli>(Clock::now() - start).count();
  }
  double remaining() const { return max(0.0, time_limit - elapsed()); }
  bool is_time_over() const { return elapsed() >= time_limit; }
};

int D, N = 26;
vector<int> c(N);
vector<vector<int>> s;

void input() {
  cin >> D;
  s.assign(D, vector<int>(N));
  rep(i, 0, N) cin >> c[i];
  rep(i, 0, D) rep(j, 0, N) cin >> s[i][j];
}

ll tri(ll x) {
  return x * (x + 1) / 2;
}

ll calc_score(const vector<int>& t) {
  vector<int> last(N, -1);
  ll score = 0;
  rep(d, 0, D) {
    score += s[d][t[d]];
    last[t[d]] = d;
    rep(i, 0, N) {
      score -= 1LL * c[i] * (d - last[i]);
    }
  }
  return score;
}

ll calc_delta(const vector<int>& t, int d, int new_type) {
  int old_type = t[d];
  int prev_old = -1, next_old = D;
  int prev_new = -1, next_new = D;
  rrep(i, 0, d) {
    if (t[i] == old_type) {
      prev_old = i;
      break;
    }
  }
  rep(i, d + 1, D) {
    if (t[i] == old_type) {
      next_old = i;
      break;
    }
  }
  rrep(i, 0, d) {
    if (t[i] == new_type) {
      prev_new = i;
      break;
    }
  }
  rep(i, d + 1, D) {
    if (t[i] == new_type) {
      next_new = i;
      break;
    }
  }
  ll delta = s[d][new_type] - s[d][old_type];
  ll old_penalty_delta =
      c[old_type] * (tri(next_old - prev_old - 1LL) - tri(d - prev_old - 1LL) - tri(next_old - d - 1LL));
  ll new_penalty_delta =
      c[new_type] * (tri(d - prev_new - 1LL) + tri(next_new - d - 1LL) - tri(next_new - prev_new - 1LL));
  delta -= old_penalty_delta;
  delta -= new_penalty_delta;
  return delta;
}

void solve() {
  vector<int> t(D, 0);
  ll score = calc_score(t);
  TimeKeeper tk(1900);
  const double temp = 100.0;
  while (!tk.is_time_over()) {
    int d = randrange(0, D);
    int old_type = t[d];
    int new_type = randrange(0, N - 1);
    if (new_type >= old_type) new_type++;
    ll delta = calc_delta(t, d, new_type);
    double prob = exp(static_cast<double>(delta) / temp);
    if (delta >= 0 or randdouble() < prob) {
      t[d] = new_type;
      score += delta;
    }
  }
  rep(i, 0, D) cout << t[i] + 1 << '\n';
  cerr << score << ' ' << calc_score(t) << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}
