#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll k, dist[1 << 18];
bool used[1 << 18];
vector<pair<ll, ll>> G[1 << 18];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;

void dijkstra()
{
  for (ll i = 0; i < k; i++)
    dist[i] = (1 << 30);
  for (ll i = 0; i < k; i++)
    used[i] = false;
  Q.push(make_pair(0, 0));
  while (!Q.empty())
  {
    ll pos = Q.top().second;
    Q.pop();
    if (used[pos] == true)
      continue;
    used[pos] = true;
    for (pair<ll, ll> i : G[pos])
    {
      ll to = i.first, cost = dist[pos] + i.second;
      if (pos == 0)
        cost = i.second;
      if (dist[to] > cost)
      {
        dist[to] = cost;
        Q.push(make_pair(dist[to], to));
      }
    }
  }
}

int main()
{
  cin >> k;
  rep(i, k)
  {
    rep(j, 10)
    {
      if (i == 0 and j == 0)
        continue;
      G[i].push_back(make_pair((i * 10 + j) % k, j));
    }
  }
  dijkstra();
  cout << dist[0] << endl;
}