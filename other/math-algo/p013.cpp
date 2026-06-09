#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

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

int main()
{
  ll n;
  cin >> n;
  for (ll x : divisors(n))
    cout << x << endl;
}
