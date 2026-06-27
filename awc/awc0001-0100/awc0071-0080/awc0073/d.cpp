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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, ll>>> g(m);
  rep(_, 0, k) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  auto dist = warshall_floyd(g);
  ll ans = 0;
  rep(_, 0, n) {
    int s, t;
    cin >> s >> t;
    s--, t--;
    ans += dist[s][t];
  }
  cout << ans << '\n';
  return 0;
}