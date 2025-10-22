#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 1; i < n; i++)
    cin >> a[i];
  vector<ll> sum(n);
  sum[0] = 0;
  for (int i = 1; i < n; i++)
    sum[i] = sum[i - 1] + a[i];
  ll m;
  cin >> m;
  vector<ll> b(m);
  rep(i, m) { cin >> b[i]; }
  ll ans = 0;
  rep(i, m - 1)
  {
    ll l = b[i], r = b[i + 1];
    if (l > r)
      swap(l, r);
    ans += sum[r - 1] - sum[l - 1];
  }
  cout << ans << endl;
}
