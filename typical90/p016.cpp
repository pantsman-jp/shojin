#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  ll ans = inf;
  rep(i, 0, 10000)
  {
    rep(j, 0, 10000 - i)
    {
      ll rest = n - a * i - b * j;
      if (rest < 0)
        break;
      if (rest % c == 0)
        ans = min(ans, i + j + rest / c);
    }
  }
  cout << ans << endl;
}
