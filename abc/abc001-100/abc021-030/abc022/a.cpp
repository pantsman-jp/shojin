#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, s, t, w;
  cin >> n >> s >> t >> w;
  vector<ll> weight = {w};
  rep(_, 0, n - 1)
  {
    ll a;
    cin >> a;
    weight.push_back(weight.back() + a);
  }
  int ans = 0;
  for (ll x : weight)
    if (s <= x and x <= t)
      ans++;
  cout << ans << endl;
}