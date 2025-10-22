#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n + 1);
  rep(i, m)
  {
    ll a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<ll> dist(n + 1, -1);
  for (ll i = 1; i < n + 1; i++)
  {
    if (dist[i] != -1)
      continue;
    queue<ll> q;
    q.push(i), dist[i] = 0;
    while (!q.empty())
    {
      ll v = q.front();
      q.pop();
      for (ll nv : g[v])
      {
        if (dist[nv] == -1)
          dist[nv] = 1 - dist[v], q.push(nv);
        else if (dist[nv] == dist[v])
        {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}
