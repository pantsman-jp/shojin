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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  int ans = n + 1;
  rep(x, 0, 1 << n)
  {
    bool ok = true;
    rep(i, 0, m)
    {
      bool can = false;
      rep(j, 0, n)
      {
        if (x >> j & 1)
        {
          if (s[j][i] == 'o')
          {
            can = true;
            break;
          }
        }
      }
      if (!can)
      {
        ok = false;
        break;
      }
    }
    if (ok)
      ans = min(ans, __builtin_popcount(x));
  }
  cout << ans << endl;
}