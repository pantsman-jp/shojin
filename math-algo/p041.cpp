#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll t, n;
  cin >> t >> n;
  vector<ll> b(t + 1), a(t + 1);
  for (int i = 1; i <= n; i++)
  {
    ll l, r;
    cin >> l >> r;
    b[l] += 1, b[r] -= 1;
  }
  a[0] = b[0];
  for (int i = 1; i <= t; i++)
    a[i] = a[i - 1] + b[i];
  for (int i = 0; i < t; i++)
    cout << a[i] << endl;
}
