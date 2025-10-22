#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll gcd_all(vector<ll> xs)
{
  ll ans = xs[0];
  for (int i = 1; i < xs.size(); i++)
    ans = gcd(ans, xs[i]);
  return ans;
}

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) { cin >> a[i]; }
  cout << gcd_all(a) << endl;
}
