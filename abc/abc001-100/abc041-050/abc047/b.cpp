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
  int w, h, n;
  cin >> w >> h >> n;
  int lx = 0, rx = w, ly = 0, ry = h;
  rep(_, 0, n)
  {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1)
      lx = max(lx, x);
    else if (a == 2)
      rx = min(rx, x);
    else if (a == 3)
      ly = max(ly, y);
    else
      ry = min(ry, y);
  }
  if (lx <= rx and ly <= ry)
    cout << (rx - lx) * (ry - ly) << endl;
  else
    cout << 0 << endl;
}