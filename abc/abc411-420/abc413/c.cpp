#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ll q;
  cin >> q;
  queue<pair<ll, ll>> a;
  rep(_, q)
  {
    ll n;
    cin >> n;
    if (n == 1)
    {
      ll c, x;
      cin >> c >> x;
      a.push({c, x});
    }
    else
    {
      ll k;
      cin >> k;
      ll ans = 0;
      while (k > 0)
      {
        auto [c, x] = a.front();
        if (c <= k)
        {
          ans += c * x;
          k -= c;
          a.pop();
        }
        else
        {
          ans += k * x;
          a.front().first -= k;
          k = 0;
        }
      }
      cout << ans << endl;
    }
  }
}