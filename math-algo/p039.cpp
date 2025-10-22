#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n, q;
  cin >> n >> q;
  vector<ll> b(n + 2);
  rep(_, q)
  {
    ll l, r, x;
    cin >> l >> r >> x;
    b[l] += x, b[r + 1] -= x;
  }
  vector<ll> a(n + 1);
  for (ll i = 1; i <= n; i++)
    a[i] = a[i - 1] + b[i];
  for (ll i = 1; i < n; i++)
  {
    if (a[i] > a[i + 1])
      cout << '>';
    else if (a[i] == a[i + 1])
      cout << '=';
    else
      cout << '<';
  }
  cout << endl;
}
