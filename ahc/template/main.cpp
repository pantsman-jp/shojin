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

using Clock = chrono::steady_clock;
using Timer = chrono::time_point<Clock>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// [l, r)
int randrange(int l, int r) {
  return uniform_int_distribution<int>(l, r - 1)(rng);
}

// [0.0, 1.0)
double randdouble() { return uniform_real_distribution<double>(0.0, 1.0)(rng); }

struct TimeKeeper {
  Timer start;
  double time_limit;
  explicit TimeKeeper(double time_limit)
      : start(Clock::now()), time_limit(time_limit) {}
  double elapsed() const {
    return chrono::duration<double>(Clock::now() - start).count();
  }
  double remaining() const { return max(0.0, time_limit - elapsed()); }
  bool is_time_over() const { return elapsed() >= time_limit; }
};

void input() {}

void solve() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}
