#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  map<ll, ll> cnt;
  rep(_, n)
  {
    ll a;
    cin >> a;
    cnt[a]++;
  }
  ll ans = 0;
  for (ll i = 1; i < 50000; i++)
    ans += cnt[i] * cnt[100000 - i];
  ans += cnt[50000] * (cnt[50000] - 1) / 2;
  cout << ans << endl;
}
