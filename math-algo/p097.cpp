#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}