#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, s, m, l;
  cin >> n >> s >> m >> l;
  int ans = 100000000;
  rep(x, 101)
  {
    rep(y, 101)
    {
      rep(z, 101)
      {
        if (6 * x + 8 * y + 12 * z >= n)
          ans = min(ans, x * s + y * m + z * l);
      }
    }
  }
  cout << ans << endl;
}
