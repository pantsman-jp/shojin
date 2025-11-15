#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll dist(ll x1, ll y1, ll x2, ll y2)
{
  return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(n), c(m), d(m);
  rep(i, 0, n) cin >> a[i] >> b[i];
  rep(j, 0, m) cin >> c[j] >> d[j];
  rep(i, 0, n)
  {
    ll best = inf, ans = 0;
    rep(j, 0, m)
    {
      ll now = dist(a[i], b[i], c[j], d[j]);
      if (now < best)
        ans = j + 1, best = now;
    }
    cout << ans << endl;
  }
}