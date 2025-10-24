#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (long long i = (a); i < (b); i++)
using ll = long long;
const ll mod = 1000000007;

ll binpower(ll a, ll b)
{
  ll ans = 1;
  while (b != 0)
  {
    if (b % 2 == 1)
      ans = ans * a % mod;
    a = a * a % mod, b /= 2;
  }
  return ans;
}

int main()
{
  ll n, k;
  cin >> n >> k;
  if (k == 1)
  {
    if (n == 1)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  if (n == 1)
  {
    cout << k % mod << endl;
    return 0;
  }
  if (n == 2)
  {
    cout << k * (k - 1) % mod << endl;
    return 0;
  }
  else
  {
    cout << k * (k - 1) % mod * binpower(k - 2, n - 2) % mod << endl;
    return 0;
  }
}