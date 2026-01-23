#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod = 998244353;
// const ll mod = 1000000007;

vector<ll> dijkstra(const vector<vector<pair<int, ll>>> &g, int s)
{
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  pq.push({0, s});
  while (!pq.empty())
  {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u])
      continue;
    for (auto [v, w] : g[u])
    {
      ll nd = d + w;
      if (nd < dist[v])
      {
        dist[v] = nd;
        pq.push({nd, v});
      }
    }
  }
  return dist;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<vector<pair<int, ll>>> g(n);
  rep(_, 0, m)
  {
    int u, v;
    ll b;
    cin >> u >> v >> b;
    u--, v--;
    g[u].push_back({v, b + a[v]});
    g[v].push_back({u, b + a[u]});
  }
  vector<ll> dist = dijkstra(g, 0);
  rep(i, 1, n) cout << dist[i] + a[0] << " ";
  cout << endl;
}