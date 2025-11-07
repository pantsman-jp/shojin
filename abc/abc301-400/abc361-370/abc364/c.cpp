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
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  sort(all(a), greater<ll>()), sort(all(b), greater<ll>());
  ll c1 = 0, c2 = 0, sx = 0, sy = 0;
  rep(i, 0, n)
  {
    sx += a[i], c1++;
    if (sx > x)
      break;
  }
  rep(i, 0, n)
  {
    sy += b[i], c2++;
    if (sy > y)
      break;
  }
  cout << min(c1, c2) << endl;
}