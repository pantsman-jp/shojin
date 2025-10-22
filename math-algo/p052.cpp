#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll modpow(ll a, ll b, ll m)
{
  ll p = a, ans = 1;
  rep(i, 30)
  {
    if ((b & (1 << i)) != 0)
      ans = (ans * p) % m;
    p = (p * p) % m;
  }
  return ans;
}

ll moddiv(ll a, ll b, ll m) { return (a * modpow(b, m - 2, m)) % m; }

int main()
{
  ll x, y;
  cin >> x >> y;
  if (((2 * y - x) % 3 != 0 and (2 * x - y) % 3 != 0) or ((2 * y - x) < 0 or (2 * x - y) < 0))
  {
    cout << 0 << endl;
    return 0;
  }
  ll a = (2 * y - x) / 3, m = (x + y) / 3, bunshi = 1, bunbo = 1;
  for (ll i = 1; i <= m; i++)
    bunshi = (bunshi * i) % mod;
  for (ll i = 1; i <= a; i++)
    bunbo = (bunbo * i) % mod;
  for (ll i = 1; i <= m - a; i++)
    bunbo = (bunbo * i) % mod;
  cout << moddiv(bunshi, bunbo, mod) << endl;
}
