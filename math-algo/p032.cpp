#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n, x;
  cin >> n >> x;
  vector<ll> a(n);
  rep(i, n) { cin >> a[i]; }
  sort(a.begin(), a.end());
  ll l = 0, r = n - 1;
  while (l <= r)
  {
    ll mid = (l + r) / 2;
    if (x == a[mid])
    {
      cout << "Yes" << endl;
      return 0;
    }
    if (x < a[mid])
      r = mid - 1;
    if (x > a[mid])
      l = mid + 1;
  }
  cout << "No" << endl;
}
