#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int ans = 0;
  rep(i, a + 1)
  {
    rep(j, b + 1)
    {
      rep(k, c + 1)
      {
        if (500 * i + 100 * j + 50 * k == x)
          ans++;
      }
    }
  }
  cout << ans << endl;
}