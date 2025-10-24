#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;

const ld pi = 3.14159265358979;

ld t, l, x, y;

void solve()
{
  ld e;
  cin >> e;
  ld zt = l * (1 - cos(2 * pi * e / t)) / 2.0;
  ld yt = -l * sin(2 * pi * e / t) / 2.0;
  cout << fixed << setprecision(10) << atan2(zt, sqrt(x * x + (y - yt) * (y - yt))) * 180 / pi << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t >> l >> x >> y;
  ll q;
  cin >> q;
  rep(qi, 0, q) solve();
}
