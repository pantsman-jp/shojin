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
  const ll M = 1e8;
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  ll ans = 0;
  rep(i, 0, n) ans += a[i] * (n - 1);
  ll r = n - 1;
  rep(i, 0, n)
  {
    while (r >= 0 && a[i] + a[r] >= M)
      r--;
    ans -= (n - max(r, i) - 1) * M;
  }
  cout << ans << endl;
}