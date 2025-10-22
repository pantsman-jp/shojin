#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll floor(ll x, ll m)
{
  return (x - ((x % m + m) % m)) / m;
}

int main()
{
  ll a, m, l, r;
  cin >> a >> m >> l >> r;
  l -= a, r -= a;
  cout << floor(r, m) - floor(l - 1, m) << endl;
}