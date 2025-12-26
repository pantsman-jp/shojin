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
// const ll mod =;

int n;
vector<vector<int>> g;

P bfs(int start)
{
  vector<int> dist(n, -1);
  queue<int> q;
  q.push(start);
  dist[start] = 0;
  int farthest = start;
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for (int u : g[v])
    {
      if (dist[u] == -1)
      {
        dist[u] = dist[v] + 1;
        q.push(u);
        if (dist[u] > dist[farthest])
          farthest = u;
      }
    }
  }
  return {farthest, dist[farthest]};
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  g.resize(n);
  rep(_, 0, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  cout << bfs(bfs(0).first).second + 1 << endl;
}