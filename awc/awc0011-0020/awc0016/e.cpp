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
  vector<ll> p(n);
  rep(i, 0, n) cin >> p[i];
  int s, t;
  cin >> s >> t;
  s--, t--;
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  rep(i, 0, n) dist[i][i] = 0;
  rep(i, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    dist[u][v] = dist[v][u] = w;
  }
  rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
    if (dist[i][k] != INF and dist[k][j] != INF)
      chmin(dist[i][j], dist[i][k] + dist[k][j]);
  }
  vector<vector<ll>> dp(1 << n, vector<ll>(n, -INF));
  dp[1 << s][s] = p[s];
  rep(mask, 1, 1 << n) rep(u, 0, n) {
    if (!(mask & (1 << u)) or dp[mask][u] == -INF) continue;
    rep(v, 0, n) {
      if (mask & (1 << v) or dist[u][v] == INF) continue;
      chmax(dp[mask | (1 << v)][v], dp[mask][u] + p[v] - dist[u][v]);
    }
  }
  ll ans = -INF;
  rep(mask, 1, 1 << n) if (mask & (1 << t)) chmax(ans, dp[mask][t]);
  cout << ans << '\n';
  return 0;
}