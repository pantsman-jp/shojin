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

vector<vector<ll>> warshall_floyd(const vector<vector<pair<int, ll>>>& g) {
  int n = g.size();
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  rep(i, 0, n) dist[i][i] = 0;
  rep(i, 0, n) for (const auto& e : g[i]) chmin(dist[i][e.first], e.second);
  rep(k, 0, n) rep(i, 0, n) {
    if (dist[i][k] < INF) {
      rep(j, 0, n) {
        if (dist[k][j] < INF) chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  rep(_, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    g[u - 1].emplace_back(v - 1, w);
  }
  int s, k;
  cin >> s >> k;
  s--;
  vector<int> t(k);
  rep(i, 0, k) {
    cin >> t[i];
    t[i]--;
  }
  auto dist = warshall_floyd(g);
  vector<int> nodes;
  nodes.push_back(s);
  rep(i, 0, k) nodes.push_back(t[i]);
  int sz = nodes.size();
  vector dp(1 << sz, vector<ll>(sz, INF));
  dp[1][0] = 0;
  rep(mask, 1, 1 << sz) rep(i, 0, sz) {
    if (dp[mask][i] == INF) continue;
    rep(j, 0, sz) {
      if (!(mask >> j & 1)) {
        ll d = dist[nodes[i]][nodes[j]];
        if (d < INF) chmin(dp[mask | (1 << j)][j], dp[mask][i] + d);
      }
    }
  }
  ll ans = INF;
  int final_mask = (1 << sz) - 1;
  rep(i, 1, sz) {
    if (dp[final_mask][i] < INF) {
      ll d = dist[nodes[i]][s];
      if (d < INF) chmin(ans, dp[final_mask][i] + d);
    }
  }
  if (ans == INF)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
  return 0;
}