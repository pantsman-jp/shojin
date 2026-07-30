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
using mint = modint998244353;
// using mint = modint1000000007;

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  rep(i, 0, t) solve();
  return 0;
}

void solve() {
  string N;
  cin >> N;
  using tiii = tuple<int, int, int>;
  map<tiii, mint> dp;
  dp[tiii(0, 0, 0)] = 1;
  for (char c : N) {
    c -= '0';
    map<tiii, mint> old;
    swap(old, dp);
    for (auto [t, x] : old) {
      auto [j, k, s] = t;
      rep(d, 0, 10) {
        int nj = j, nk = (k * 10 + d) % 3, ns = s | 1 << d;
        if (nj == 0 and d > c) continue;
        if (d < c) nj = 1;
        if (s == 0 and d == 0) ns = 0;
        dp[tiii(nj, nk, ns)] += x;
      }
    }
  }
  mint ans;
  for (auto [t, x] : dp) {
    auto [j, k, s] = t;
    int cnt = 0;
    if (k == 0) cnt++;
    if (s >> 3 & 1) cnt++;
    if (__builtin_popcount(s) == 3) cnt++;
    if (cnt == 1) ans += x;
  }
  ans -= 1;
  cout << ans.val() << '\n';
}