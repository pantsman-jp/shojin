#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector g(n, vector<int>(n));
  rep(i, 0, n) rep(j, 0, n) g[i][j] = -1;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    rep(j, 0, a)
    {
      int x, y;
      cin >> x >> y;
      x--;
      g[i][x] = y;
    }
  }
  int ans = 0;
  rep(bit, 0, 1 << n)
  {
    vector<int> d(n);
    rep(j, 0, n) if (bit >> j & 1) d[j] = 1;
    bool ok = true;
    rep(j, 0, n)
    {
      if (d[j] != 0)
      {
        rep(k, 0, n)
        {
          if (g[j][k] == -1)
            continue;
          if (g[j][k] != d[k])
            ok = false;
        }
      }
    }
    if (ok)
      ans = max(ans, __builtin_popcount(bit));
  }
  cout << ans << endl;
}