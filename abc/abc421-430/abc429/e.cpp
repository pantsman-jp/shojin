#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(i, 0, m)
  {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }
  string s;
  cin >> s;
  vector<int> safe, danger;
  rep(i, 0, n)
  {
    if (s[i] == 'S')
      safe.push_back(i);
    else
      danger.push_back(i);
  }
  vector<ll> dist(n, inf);
  vector<int> from(n, -1);
  queue<int> q;
  for (auto v : safe)
    dist[v] = 0, from[v] = v, q.push(v);
  while (!q.empty())
  {
    int v = q.front();
    q.pop();
    for (auto nx : g[v])
      if (dist[nx] == inf)
        dist[nx] = dist[v] + 1, from[nx] = from[v], q.push(nx);
  }
  vector<ll> ans(n, inf);
  rep(u, 0, n)
  {
    for (auto v : g[u])
    {
      if (from[u] != from[v])
      {
        ll cand = dist[u] + dist[v] + 1;
        if (s[u] == 'D')
          ans[u] = min(ans[u], cand);
        if (s[v] == 'D')
          ans[v] = min(ans[v], cand);
      }
    }
  }
  sort(danger.begin(), danger.end());
  for (auto v : danger)
  {
    if (ans[v] == inf)
      cout << -1 << endl;
    else
      cout << ans[v] << endl;
  }
}
