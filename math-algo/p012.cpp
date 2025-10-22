#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

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

int main()
{
  ll n;
  cin >> n;
  if (is_prime(n))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
