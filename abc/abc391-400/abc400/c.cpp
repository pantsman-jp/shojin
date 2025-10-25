#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i < 60; i++)
  {
    ll x = n;
    rep(j, 0, i) x /= 2;
    ll m = sqrtl(x);
    ans += (m + 1) / 2;
  }
  cout << ans << endl;
}