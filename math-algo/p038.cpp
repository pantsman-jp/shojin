#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> a(n + 1), sum(n + 1);
  for (int i = 1; i < n + 1; i++)
    cin >> a[i];
  sum[0] = 0;
  for (int i = 1; i < n + 1; i++)
    sum[i] = sum[i - 1] + a[i];
  rep(_, q)
  {
    ll l, r;
    cin >> l >> r;
    cout << sum[r] - sum[l - 1] << endl;
  }
}
