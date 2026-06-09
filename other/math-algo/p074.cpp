#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n + 1);
  for (ll i = 1; i < n + 1; i++)
    cin >> a[i];
  ll ans = 0;
  for (ll i = 1; i < n + 1; i++)
    ans += a[i] * (-n + 2 * i - 1);
  cout << ans << endl;
}
