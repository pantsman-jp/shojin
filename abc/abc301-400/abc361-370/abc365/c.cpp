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
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  if (reduce(all(a)) <= m)
  {
    cout << "infinite" << endl;
    return 0;
  }
  ll l = 0, r = *max_element(all(a)) + 1;
  while (r - l > 1)
  {
    ll mid = (l + r) / 2, total = 0;
    rep(i, 0, n) total += min(a[i], mid);
    if (total <= m)
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
}