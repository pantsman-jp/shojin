#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

// 素数判定
bool is_prime(ll n)
{
  if (n < 2)
    return false;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

// 素数列挙
vector<ll> primes(ll n)
{
  vector<bool> prime(n + 2, true);
  prime[0] = prime[1] = false;
  for (ll i = 2; i * i <= n; i++)
    if (prime[i])
      for (ll x = i * i; x <= n; x += i)
        prime[x] = false;
  vector<ll> ans;
  for (ll i = 2; i <= n; i++)
    if (prime[i])
      ans.push_back(i);
  return ans;
}

// 約数列挙
vector<ll> divisors(ll n)
{
  vector<ll> ans;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    ans.push_back(i);
    if (i != n / i)
      ans.push_back(n / i);
  }
  sort(ans.begin(), ans.end());
  return ans;
}

// 素因数分解
vector<ll> factorization(ll n)
{
  vector<ll> ans;
  for (ll i = 2; i * i <= n; i++)
  {
    while (n % i == 0)
      ans.push_back(i), n /= i;
  }
  if (n > 1)
    ans.push_back(n);
  return ans;
}

// 最大公約数
ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll gcd_all(vector<ll> xs)
{
  ll ans = xs[0];
  for (ll i = 1; i < xs.size(); i++)
    ans = gcd(ans, xs[i]);
  return ans;
}

// 最小公倍数
ll lcm(ll a, ll b)
{
  return a / gcd(a, b) * b;
}

ll lcm_all(vector<ll> xs)
{
  ll ans = xs[0];
  for (ll i = 1; i < xs.size(); i++)
    ans = lcm(ans, xs[i]);
  return ans;
}

// 順列
ll npr(ll n, ll r)
{
  ll ans = 1;
  rep(i, r) { ans *= (n - i); }
  return ans;
}

ll ncr(ll n, ll r)
{
  if (r > n - r)
    r = n - r;
  ll ans = 1;
  rep(i, r) { ans = ans * (n - i) / (i + 1); }
  return ans;
}

// 巨大素数の余りの計算(modpow は 繰り返し二乗法 pow(a,b)(mod m), div は a÷b(mod m) を計算する)
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

ll div(ll a, ll b, ll m) { return (a * modpow(b, m - 2, m)) % m; }
