#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll mod = 1000000007;

ll modpow(ll a, ll b, ll m)
{
  ll ans = 1;
  while (b > 0)
  {
    if (b & 1)
      ans = (ans * a) % m;
    a = (a * a) % m;
    b >>= 1;
  }
  return ans;
}

ll moddiv(ll a, ll b, ll m) { return (a * modpow(b, m - 2, m)) % m; }

int main()
{
  ll n;
  cin >> n;
  ll bunshi = (modpow(4, n + 1, mod) - 1 + mod) % mod;
  cout << moddiv(bunshi, 3, mod) << endl;
}
