#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "YES\n" : "NO\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;

ld distance(ld x1, ld y1, ld x2, ld y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ld sx, sy, tx, ty, t, v;
  int n;
  cin >> sx >> sy >> tx >> ty >> t >> v >> n;
  ld mn = INF;
  rep(i, 0, n)
  {
    ld x, y;
    cin >> x >> y;
    chmin(mn, distance(x, y, sx, sy) + distance(x, y, tx, ty));
  }
  yn(mn <= t * v);
}