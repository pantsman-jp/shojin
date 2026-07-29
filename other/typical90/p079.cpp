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
// using mint = modint998244353;
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
  int h, w;
  cin >> h >> w;
  vector a(h, vector<ll>(w)), b(h, vector<ll>(w)), c(h, vector<ll>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  rep(i, 0, h) rep(j, 0, w) cin >> b[i][j];
  rep(i, 0, h) rep(j, 0, w) c[i][j] = b[i][j] - a[i][j];
  ll ans = 0;
  rep(i, 0, h - 1) rep(j, 0, w - 1) {
    ll diff = c[i][j];
    ans += abs(diff);
    rep(di, 0, 2) rep(dj, 0, 2) c[i + di][j + dj] -= diff;
  }
  bool ok = true;
  rep(i, 0, h) if (c[i][w - 1] != 0) ok = false;
  rep(j, 0, w) if (c[h - 1][j] != 0) ok = false;
  yn(ok);
  if (ok) cout << ans << '\n';
}