#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> visited;

void dfs(ll v)
{
  visited[v] = true;
  for (ll i : g[v])
    if (!visited[i])
      dfs(i);
}

int main()
{
  ll n, m;
  cin >> n >> m;
  g.assign(n, {});
  visited.assign(n, false);
  rep(_, m)
  {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  dfs(0);
  for (bool b : visited)
  {
    if (!b)
    {
      cout << "The graph is not connected." << endl;
      return 0;
    }
  }
  cout << "The graph is connected." << endl;
}
