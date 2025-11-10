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
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--, y--;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int ans = 1;
  for (int i = x - 1; i >= 0; i--)
  {
    if (s[i][y] == '#')
      break;
    ans++;
  }
  for (int i = x + 1; i < h; i++)
  {
    if (s[i][y] == '#')
      break;
    ans++;
  }
  for (int j = y - 1; j >= 0; j--)
  {
    if (s[x][j] == '#')
      break;
    ans++;
  }
  for (int j = y + 1; j < w; j++)
  {
    if (s[x][j] == '#')
      break;
    ans++;
  }
  cout << ans << endl;
}