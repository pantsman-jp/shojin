#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  rep(i, 0, k) cin >> a[i], a[i]--;
  vector<ll> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  ll ans = 0;
  rep(i, 0, n)
  {
    ll tmp = inf;
    rep(j, 0, k) tmp = min(tmp, dist(x[i], y[i], x[a[j]], y[a[j]]));
    ans = max(ans, tmp);
  }
  cout << fixed << setprecision(10) << sqrt((long double)ans) << endl;
}