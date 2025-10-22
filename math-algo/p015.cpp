#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
  while (1 <= a and 1 <= b)
  {
    if (a < b)
      b = b % a;
    else
      a = a % b;
  }
  if (1 <= a)
    return a;
  return b;
}

int main()
{
  ll a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
}
