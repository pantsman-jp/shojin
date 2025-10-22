#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll ncr(ll n, ll r)
{
  if (r > n - r)
    r = n - r;
  ll ans = 1;
  rep(i, r) { ans = ans * (n - i) / (i + 1); }
  return ans;
}

int main()
{
  int n, r;
  cin >> n >> r;
  cout << ncr(n, r) << endl;
}
