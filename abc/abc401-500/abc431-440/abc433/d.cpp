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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), modpow10(11, 1);
  rep(i, 0, n) cin >> a[i];
  rep(i, 1, 11) modpow10[i] = (modpow10[i - 1] * 10) % m;
  vector<map<ll, ll>> cnt(11);
  for (ll x : a)
    cnt[to_string(x).size()][x % m]++;
  ll ans = 0;
  for (ll x : a)
  {
    rep(l, 1, 11)
    {
      ll need_y = (m - (x * modpow10[l]) % m) % m;
      if (cnt[l].count(need_y) != 0)
        ans += cnt[l][need_y];
    }
  }
  cout << ans << endl;
}