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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int lx = w + 1, ly = h + 1, rx = -1, ry = -1;
  rep(i, 0, h) rep(j, 0, w)
  {
    if (s[i][j] == '#')
      ly = min(ly, i), lx = min(lx, j), ry = max(ry, i), rx = max(rx, j);
  }
  rep(i, ly, ry + 1) rep(j, lx, rx + 1)
  {
    if (s[i][j] == '.')
    {
      cout << i + 1 << ' ' << j + 1 << endl;
      return 0;
    }
  }
}