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

set<int> g;
ll t;

vector<ll> dijkstra(const vector<vector<pair<int, ll>>>& graph, int s) {
  using pli = pair<ll, int>;
  priority_queue<pli, vector<pli>, greater<pli>> pq;
  vector<ll> dist(graph.size(), INF);
  ll start_cost = (g.count(s) == 1) ? t : 0;
  dist[s] = start_cost;
  pq.push({start_cost, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : graph[u]) {
      ll cost = w + ((g.count(v) == 1) ? t : 0);
      ll nd = d + cost;
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
  cin >> n >> m >> k >> t;
  vector<vector<pair<int, ll>>> graph(n);
  rep(_, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }
  rep(i, 0, k) {
    int x;
    cin >> x;
    g.insert(x - 1);
  }
  cout << dijkstra(graph, 0)[n - 1] << '\n';
  return 0;
}