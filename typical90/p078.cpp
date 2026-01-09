#include <bits/stdc++.h>
using namespace std;
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
  rep(_, 0, m)
  {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  int ans = 0;
  rep(i, 0, n)
  {
    int cnt = 0;
    for (int x : g[i])
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
