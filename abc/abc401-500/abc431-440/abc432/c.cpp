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
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) if ((a[i] * x) % (y - x) != (a[0] * x) % (y - x))
  {
    cout << -1 << endl;
    return 0;
  }
  ll mod = (a[0] * x) % (y - x), l = -inf, r = inf, sumq = 0;
  rep(i, 0, n)
  {
    ll q = (a[i] * x - mod) / (y - x);
    l = max(l, q), r = min(r, q + a[i]), sumq += q;
  }
  if (l > r)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << n * r - sumq << endl;
}