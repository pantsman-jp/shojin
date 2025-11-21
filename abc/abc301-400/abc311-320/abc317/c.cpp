#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n, m;
vector<vector<pair<int, ll>>> edge;
ll ans = 0;

void dfs(int v, vector<bool> &visited, ll sum)
{
  ans = max(ans, sum);
  for (auto [to, cost] : edge[v])
  {
    if (!visited[to])
    {
      visited[to] = true;
      dfs(to, visited, sum + cost);
      visited[to] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  edge.resize(n + 1);
  rep(i, 0, m)
  {
    int a, b;
    ll c;
    cin >> a >> b >> c;
    edge[a].push_back({b, c}), edge[b].push_back({a, c});
  }
  rep(start, 1, n + 1)
  {
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    dfs(start, visited, 0);
  }
  cout << ans << endl;
}