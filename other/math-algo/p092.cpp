#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

vector<ll> divisors(ll n)
{
  vector<ll> ans;
  for (ll i = 1; i * i <= n; i++)
  {
    if (n % i != 0)
      continue;
    ans.push_back(i);
    if (i != n / i)
      ans.push_back(n / i);
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll ans = inf;
  for (ll x : divisors(n))
    ans = min(ans, 2 * (x + n / x));
  cout << ans << endl;
}