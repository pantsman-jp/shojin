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
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  int dx = tx - sx, dy = ty - sy;
  string ans = "";
  rep(i, 0, dx) ans += "R";
  rep(i, 0, dy) ans += "U";
  rep(i, 0, dx) ans += "L";
  rep(i, 0, dy) ans += "D";
  ans += "D";
  rep(i, 0, dx + 1) ans += "R";
  rep(i, 0, dy + 1) ans += "U";
  ans += "LU";
  rep(i, 0, dx + 1) ans += "L";
  rep(i, 0, dy + 1) ans += "D";
  cout << ans + "R" << endl;
}