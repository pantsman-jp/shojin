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
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  rep(i1, 0, h) rep(j1, 0, w) rep(i2, i1 + 1, h) rep(j2, j1 + 1, w)
  {
    if (a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}