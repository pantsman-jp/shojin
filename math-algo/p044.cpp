#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n + 1);
  rep(_, m)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<ll> dist(n + 1, -1);
  queue<ll> q;
  q.push(1), dist[1] = 0;
  while (!q.empty())
  {
    ll pos = q.front();
    q.pop();
    rep(i, g[pos].size())
    {
      ll nex = g[pos][i];
      if (dist[nex] == -1)
        dist[nex] = dist[pos] + 1, q.push(nex);
    }
  }
  for (ll i = 1; i < n + 1; i++)
    cout << dist[i] << endl;
}
