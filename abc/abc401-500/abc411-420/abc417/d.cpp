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
  int n;
  cin >> n;
  vector<ll> p(n), a(n), b(n);
  rep(i, 0, n) cin >> p[i] >> a[i] >> b[i];
  const int m = 1001;
  vector dp(n + 1, vector<int>(m));
  rep(j, 0, m) dp[n][j] = j;
  rrep(i, 0, n) rep(j, 0, m) {
    dp[i][j] = dp[i + 1][j <= p[i] ? j + a[i] : max(0LL, j - b[i])];
  }
  vector<ll> bs(n + 1);
  rep(i, 0, n) bs[i + 1] = bs[i] + b[i];
  int q;
  cin >> q;
  rep(_, 0, q) {
    ll x;
    cin >> x;
    if (x >= m) {
      int i = min(n, int(upper_bound(all(bs), x - m) - bs.begin()));
      x -= bs[i];
      cout << (i == n ? x : dp[i][x]) << '\n';
    } else {
      cout << dp[0][x] << '\n';
    }
  }
}
