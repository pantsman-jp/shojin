#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int h, w;
vector<string> s;

void change(char c, int &y, int &x)
{
  if (c == 'L')
    x--;
  else if (c == 'R')
    x++;
  else if (c == 'U')
    y--;
  else
    y++;
}

bool check(int y, int x)
{
  return 0 <= y and y < h and 0 <= x and x < w and s[y][x] == '.';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string t;
  cin >> h >> w >> n >> t;
  s.resize(h);
  rep(i, 0, h) cin >> s[i];
  int ans = 0;
  rep(i, 0, h) rep(j, 0, w)
  {
    if (s[i][j] == '#')
      continue;
    int y = i, x = j;
    bool ok = true;
    for (char c : t)
    {
      change(c, y, x);
      if (!check(y, x))
      {
        ok = false;
        break;
      }
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
}