#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define dout(x) cout << fixed << setprecision(10) << x << "\n"
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

int main() {
  int n;
  cin >> n;
  vector<ll> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  auto dist = [&](int i, int j) {
    ll dx = x[i] - x[j];
    ll dy = y[i] - y[j];
    return dx * dx + dy * dy;
  };
  const ll inf = (1LL << 62);
  vector dp(1 << (n - 1), vector<ll>(n, inf));
  rep(i, 0, n - 1) dp[1 << i][i + 1] = dist(0, i + 1);
  rep(s, 0, 1 << (n - 1)) {
    rep(u, 1, n) {
      if (!(s & (1 << (u - 1))) or dp[s][u] == inf) continue;
      rep(v, 1, n) {
        if (s & (1 << (v - 1))) continue;
        chmin(dp[s | (1 << (v - 1))][v], dp[s][u] + dist(u, v));
      }
    }
  }
  ll ans = INF;
  rep(i, 1, n) chmin(ans, dp[(1 << (n - 1)) - 1][i] + dist(i, 0));
  cout << ans << '\n';
  return 0;
}