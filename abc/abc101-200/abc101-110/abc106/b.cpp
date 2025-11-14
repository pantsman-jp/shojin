#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
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
  sort(all(ans));
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  int ans = 0;
  for (ll i = 1; i < n + 1; i += 2)
    if (divisors(i).size() == 8)
      ans++;
  cout << ans << endl;
}