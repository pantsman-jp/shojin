#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool check(ll t, ll a, ll b)
{
  return b / t - (a + t - 1) / t >= 1;
}

int main()
{
  ll a, b;
  cin >> a >> b;
  ll ans = 0;
  for (ll i = 1; i < b + 1; i++)
    if (check(i, a, b))
      ans = i;
  cout << ans << endl;
}
