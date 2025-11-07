#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, 0, h) cin >> grid[i];
  int li = h, ri = 0;
  int lj = w, rj = 0;
  rep(i, 0, h)
  {
    rep(j, 0, w)
    {
      if (grid[i][j] == '#')
      {
        li = min(li, i), ri = max(ri, i);
        lj = min(lj, j), rj = max(rj, j);
      }
    }
  }
  rep(i, li, ri + 1)
  {
    rep(j, lj, rj + 1)
    {
      if (grid[i][j] == '.')
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}