#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

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

int main()
{
  ll n;
  cin >> n;
  for (ll x : factorization(n))
    cout << x << ' ';
  cout << endl;
}
