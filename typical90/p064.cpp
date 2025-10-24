#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;

ll n, q;
vector<ll> a, b;
ll ans;

void solve()
{
  ll l, r, v;
  cin >> l >> r >> v;
  ll before = 0, after = 0;
  if (l > 1)
    before += abs(b[l - 2]);
  if (r < n)
    before += abs(b[r - 1]);
  if (l > 1)
    b[l - 2] += v;
  if (r < n)
    b[r - 1] -= v;
  if (l > 1)
    after += abs(b[l - 2]);
  if (r < n)
    after += abs(b[r - 1]);
  ans += after - before;
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];
  b.resize(n - 1);
  rep(i, 0, n - 1) b[i] = a[i + 1] - a[i];
  ans = 0;
  rep(i, 0, n - 1) ans += abs(b[i]);
  rep(i, 0, q) solve();
}
