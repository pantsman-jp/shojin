#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

vector<ll> prime_factors(ll n)
{
  ll rem = n;
  vector<ll> ans;
  for (ll i = 2; i * i <= n; i++)
    while (rem % i == 0)
      rem /= i, ans.push_back(i);
  if (rem != 1)
    ans.push_back(rem);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  int ans = 0;
  ll m = prime_factors(n).size();
  for (int i = 0; i <= 20; i++)
  {
    if ((1 << i) >= m)
    {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}
