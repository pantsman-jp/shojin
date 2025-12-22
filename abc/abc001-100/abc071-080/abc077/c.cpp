#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n) cin >> c[i];
  sort(all(a)), sort(all(b)), sort(all(c));
  ll ans = 0;
  rep(i, 0, n)
  {
    ll x = lower_bound(all(a), b[i]) - a.begin();
    ll y = c.end() - upper_bound(all(c), b[i]);
    ans += x * y;
  }
  cout << ans << endl;
}