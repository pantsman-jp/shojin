#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
using P = pair<ll, ll>;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> x(m), a(m);
  rep(i, 0, m) cin >> x[i];
  rep(i, 0, m) cin >> a[i];
  vector<P> v;
  rep(i, 0, m) v.emplace_back(x[i], a[i]);
  sort(all(v));
  ll sum = 0;
  rep(i, 0, m) sum += v[i].second;
  if (sum != n)
  {
    cout << -1 << endl;
    return 0;
  }
  ll need = 1, ans = 0;
  rep(i, 0, m)
  {
    ll pos = v[i].first, cnt = v[i].second;
    if (need < pos)
    {
      cout << -1 << endl;
      return 0;
    }
    need = max(need, pos);
    ll take = min(cnt, n - need + 1);
    ans += take * (need - pos) + take * (take - 1) / 2, need += take;
  }
  if (need != n + 1)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
}
