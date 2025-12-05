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
  ll s = 0, t = 0;
  rep(i, 0, m) s += a[i] * (i + 1), t += a[i];
  ll ans = s;
  rep(i, 0, n - m) s = s - t + (ll)m * a[i + m], t = t - a[i] + a[i + m], ans = max(ans, s);
  cout << ans << endl;
}