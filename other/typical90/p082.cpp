#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ull = unsigned long long;
using ll = long long;
const ll mod = 1000000007;
ull L, R;
ull power10[22];

ll modpow(ll a, ll b, ll m)
{
  ll p = 1, q = a;
  for (int i = 0; i < 30; i++)
  {
    if ((b & (1LL << i)) != 0)
    {
      p *= q;
      p %= m;
    }
    q *= q;
    q %= m;
  }
  return p;
}

ll Div(ll a, ll b, ll m)
{
  return (a * modpow(b, m - 2, m)) % m;
}

void init()
{
  power10[0] = 1;
  for (int i = 1; i <= 19; i++)
    power10[i] = (10ULL * power10[i - 1]);
}

ll f(ll X)
{
  ll v1 = X % mod;
  ll v2 = (X + 1) % mod;
  ll v = v1 * v2 % mod;
  return Div(v, 2, mod);
}

int main()
{
  init();
  cin >> L >> R;
  ll ans = 0;
  for (int i = 1; i <= 19; i++)
  {
    ull vl = max(L, power10[i - 1]), vr = min(R, power10[i] - 1ULL);
    if (vl > vr)
      continue;
    ll val = (f(vr) - f(vl - 1) + mod) % mod;
    ans += 1LL * i * val;
    ans %= mod;
  }
  cout << ans << endl;
}