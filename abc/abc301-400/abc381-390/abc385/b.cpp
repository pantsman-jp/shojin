#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int h, w, x, y;
  cin >> h >> w >> x >> y;
  x--;
  y--;
  vector<string> s(h);
  for (int i = 0; i < h; i++)
    cin >> s[i];
  string t;
  cin >> t;
  int ans = 0;
  if (s[x][y] == '@')
  {
    ans++;
    s[x][y] = '.';
  }
  for (char c : t)
  {
    if (c == 'U' && s[x - 1][y] != '#')
      x--;
    if (c == 'D' && s[x + 1][y] != '#')
      x++;
    if (c == 'L' && s[x][y - 1] != '#')
      y--;
    if (c == 'R' && s[x][y + 1] != '#')
      y++;
    if (s[x][y] == '@')
    {
      ans++;
      s[x][y] = '.';
    }
  }
  cout << x + 1 << " " << y + 1 << " " << ans << endl;
}
