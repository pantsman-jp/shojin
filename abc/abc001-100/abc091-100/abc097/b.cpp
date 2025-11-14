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
  ll x;
  cin >> x;
  ll ans = 1;
  rep(b, 2, x + 1)
  {
    ll val = b * b;
    while (val <= x)
    {
      ans = max(ans, val);
      if (x / val < b)
        break;
      val *= b;
    }
  }
  cout << ans << endl;
}