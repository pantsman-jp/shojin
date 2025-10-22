#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

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

ll moddiv(ll a, ll b, ll m)
{
  return (a * modpow(b, m - 2, m)) % m;
}

int main()
{
  ll x, y;
  cin >> x >> y;
  ll num = 1, deno = 1;
  for (ll i = 1; i <= x + y; i++)
    num = (num * i) % 1000000007;
  for (ll i = 1; i <= x; i++)
    deno = (deno * i) % 1000000007;
  for (ll i = 1; i <= y; i++)
    deno = (deno * i) % 1000000007;
  cout << moddiv(num, deno, 1000000007) << endl;
}
