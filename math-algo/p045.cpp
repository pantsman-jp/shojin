#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n + 1);
  rep(_, m)
  {
    ll a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  ll ans = 0;
  for (ll i = 1; i < n + 1; i++)
  {
    int cnt = 0;
    for (ll x : g[i])
    {
      if (x < i)
        cnt++;
      if (1 < cnt)
        break;
    }
    if (cnt == 1)
      ans++;
  }
  cout << ans << endl;
}
