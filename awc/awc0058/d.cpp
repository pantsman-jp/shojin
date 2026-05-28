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

vector<ll> dijkstra(const vector<vector<pair<int, ll>>>& g, int s) {
  using pli = pair<ll, int>;
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : g[u]) {
      ll nd = d + w;
      if (nd < dist[v]) {
        dist[v] = nd;
        pq.push({nd, v});
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
  k--;
  vector<vector<pair<int, ll>>> g(n);
  rep(i, 0, m) {
    int u, v;
    ll c;
    cin >> u >> v >> c;
    u--, v--;
    g[u].emplace_back(v, c);
    g[v].emplace_back(u, c);
  }
  vector<ll> start_0 = dijkstra(g, 0), start_k = dijkstra(g, k);
  if (start_0[k] == INF or start_k[n - 1] == INF)
    cout << -1 << '\n';
  else
    cout << start_0[k] + start_k[n - 1] << '\n';
  return 0;
}