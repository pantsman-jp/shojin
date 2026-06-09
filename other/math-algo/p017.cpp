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

ll lcm(ll a, ll b)
{
  return a / gcd(a, b) * b;
}

ll lcm_all(vector<ll> xs)
{
  ll ans = xs[0];
  for (ll i = 1; i < xs.size(); i++)
    ans = lcm(ans, xs[i]);
  return ans;
}

int main()
{
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) { cin >> a[i]; }
  cout << lcm_all(a) << endl;
}
