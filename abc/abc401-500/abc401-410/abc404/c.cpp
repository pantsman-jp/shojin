#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;

vector<vector<int>> g;
vector<bool> visited;

void dfs(int v)
{
  visited[v] = true;
  for (int u : g[v])
    if (!visited[u])
      dfs(u);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  g.assign(n, {}), visited.assign(n, false);
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  if (m != n)
  {
    cout << "No" << endl;
    return 0;
  }
  dfs(0);
  for (bool b : visited)
    if (!b)
    {
      cout << "No" << endl;
      return 0;
    }
  rep(i, 0, n)
  {
    if (g[i].size() != 2)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
