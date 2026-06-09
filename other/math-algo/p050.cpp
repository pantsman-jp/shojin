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
      ans *= p, ans %= m;
    p *= p, p %= m;
  }
  return ans;
}

int main()
{
  ll a, b;
  cin >> a >> b;
  cout << modpow(a, b, 1000000007) << endl;
}
