#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<vector<int>> g;
vector<bool> seen;
vector<int> dist;

void bfs(int v)
{
  queue<int> q;
  seen[v] = true;
  q.push(v);
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for (int u : g[v])
    {
      if (!seen[u])
      {
        seen[u] = true;
        dist[u] = dist[v] + 1;
        q.push(u);
      }
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  g.resize(n), seen.resize(n), dist.resize(n);
  rep(_, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
  }
  bfs(0);
  if (dist[n - 1] == 2)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}