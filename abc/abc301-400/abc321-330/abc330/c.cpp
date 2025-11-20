#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll d;
  cin >> d;
  ll ans = d;
  rep(x, 0, 2 * 1e6)
  {
    if (d <= x * x)
      ans = min(ans, x * x - d);
    else
    {
      ll y = sqrt(d - x * x);
      ans = min(ans, min(abs(x * x + y * y - d), abs(x * x + (y + 1) * (y + 1) - d)));
    }
  }
  cout << ans << endl;
}