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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n, vector<ll>(n, INF));
  rep(i, 0, n) g[i][i] = 0;
  rep(i, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    g[u][v] = w, g[v][u] = w;
  }
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
    if (g[i][k] != INF and g[k][j] != INF) chmin(g[i][j], g[i][k] + g[k][j]);
  }
  vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));
  dp[1][0] = 0;
  rep(s, 1, 1 << n) {
    rep(v, 0, n) {
      if (dp[s][v] == INF) continue;
      rep(u, 0, n) {
        if (!(s >> u & 1)) {
          chmin(dp[s | (1 << u)][u], dp[s][v] + g[v][u]);
        }
      }
    }
  }
  ll ans = INF;
  rep(i, 0, n) {
    if (dp[(1 << n) - 1][i] != INF and g[i][0] != INF) {
      chmin(ans, dp[(1 << n) - 1][i] + g[i][0]);
    }
  }
  if (ans != INF)
    cout << ans << '\n';
  else
    cout << -1 << '\n';
  return 0;
}