#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll mod = 1000000007;
const int MAX = 1000000;

ll fact[MAX + 1];

void init_fact()
{
  fact[0] = 1;
  for (int i = 1; i <= MAX; i++)
    fact[i] = fact[i - 1] * i % mod;
}

ll modpow(ll a, ll b, ll m)
{
  ll res = 1;
  a %= m;
  while (b > 0)
  {
    if (b & 1)
      res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

ll Division(ll a, ll b, ll m)
{
  return a * modpow(b, m - 2, m) % m;
}

ll ncr(int n, int r)
{
  if (r < 0 || r > n)
    return 0;
  return Division(fact[n], fact[r] * fact[n - r] % mod, mod);
}

int main()
{
  init_fact();
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; i++)
    cin >> a[i];
  ll ans = 0;
  for (ll i = 1; i <= n; i++)
    ans = (ans + a[i] * ncr(n - 1, i - 1)) % mod;
  cout << ans << endl;
}
