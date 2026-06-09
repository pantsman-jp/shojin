#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll h, w;
  cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w)), b(h, vector<ll>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  rep(i, 0, h) rep(j, 0, w) cin >> b[i][j];
  ll ans = 0;
  rep(i, 0, h - 1)
  {
    rep(j, 0, w - 1)
    {
      ll d = b[i][j] - a[i][j];
      a[i][j] += d, a[i][j + 1] += d;
      a[i + 1][j] += d, a[i + 1][j + 1] += d;
      ans += abs(d);
    }
  }
  if (a == b)
  {
    cout << "Yes" << endl;
    cout << ans << endl;
  }
  else
    cout << "No" << endl;
}
