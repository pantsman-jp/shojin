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
  vector<ll> q(n), a(n), b(n);
  rep(i, 0, n) cin >> q[i];
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  ll ans = 0;
  rep(x, 0, 1e6 + 1)
  {
    ll y = inf;
    rep(i, 0, n)
    {
      if (q[i] < a[i] * x)
        y = -inf;
      else if (b[i] > 0)
        y = min(y, (q[i] - a[i] * x) / b[i]);
    }
    ans = max(ans, x + y);
  }
  cout << ans << endl;
}