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
  ll n, t;
  cin >> n >> t;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<P> open, net_open;
  rep(i, 0, n) open.push_back({a[i], a[i] + t});
  P cur = open[0];
  rep(i, 1, n)
  {
    if (open[i].first <= cur.second)
      cur.second = max(cur.second, open[i].second);
    else
      net_open.push_back(cur), cur = open[i];
  }
  net_open.push_back(cur);
  ll ans = 0;
  for (auto &p : net_open)
    ans += p.second - p.first;
  cout << ans << endl;
}