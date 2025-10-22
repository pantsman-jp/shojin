#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n + 1), pow2(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  pow2[0] = 1;
  for (int i = 1; i <= n; i++)
    pow2[i] = (2 * pow2[i - 1]) % mod;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
  {
    ans += pow2[i - 1] * a[i];
    ans %= mod;
  }
  cout << ans << endl;
}
