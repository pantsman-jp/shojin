#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n + 1);
  rep(i, 0, m)
  {
    ll a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  int ans = 0;
  rep(i, 1, n + 1)
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
