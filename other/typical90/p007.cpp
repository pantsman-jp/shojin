#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

vector<ll> a;
ll n;

void solve()
{
  ll b, ans = inf;
  cin >> b;
  ll j = lower_bound(all(a), b) - a.begin();
  if (j < n)
    ans = min(ans, abs(b - a[j]));
  if (0 < j)
    ans = min(ans, abs(b - a[j - 1]));
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  ll q;
  cin >> q;
  rep(qi, 0, q) solve();
}
