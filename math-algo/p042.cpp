#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  ll ans = 0;
  vector<ll> divs(n + 1);
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i)
      divs[j]++;
  for (ll i = 1; i <= n; i++)
    ans += i * divs[i];
  cout << ans << endl;
}
