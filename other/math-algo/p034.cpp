#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
  ll n;
  cin >> n;
  vector<ll> x(n), y(n);
  rep(i, n) { cin >> x[i] >> y[i]; }
  ll ans = inf;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
      ans = min(ans, dist(x[i], y[i], x[j], y[j]));
  }
  cout << fixed << setprecision(10) << sqrt(ans) << endl;
}
