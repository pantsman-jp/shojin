#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

bool is_pali(ll x, ll a)
{
  vector<ll> s;
  while (x > 0)
    s.push_back(x % a), x /= a;
  ll n = s.size();
  rep(i, 0, n)
  {
    if (s[i] != s[s.size() - 1 - i])
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, n, ans = 0;
  cin >> a >> n;
  auto check = [&](string s)
  {
    ll y = stoll(s);
    if (y <= n and is_pali(y, a))
      ans += y;
  };
  rep(x, 1, 1e6)
  {
    string s = to_string(x);
    string rs = s;
    reverse(rs.begin(), rs.end());
    s += rs;
    check(s);
    s.erase(s.begin() + (s.size() / 2));
    check(s);
  }
  cout << ans << endl;
}