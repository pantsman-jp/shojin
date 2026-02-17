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
  rep(i, 0, n) {
    for (const auto& e : g[i])
      dist[i][e.first] = min(dist[i][e.first], e.second);
  }
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
    int a, b;
    ll t;
    cin >> a >> b >> t;
    a--, b--;
    g[a].emplace_back(b, t);
    g[b].emplace_back(a, t);
  }
  vector dist = warshall_floyd(g);
  ll ans = INF;
  rep(i, 0, n) {
    ll tmp = -INF;
    rep(j, 0, n) chmax(tmp, dist[i][j]);
    chmin(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}