#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;

vector<int> rot(vector<int> dir, bool right)
{
  if (right)
    return {dir[1], -dir[0]};
  else
    return {-dir[1], dir[0]};
}

int main()
{
  int h, w, n;
  cin >> h >> w >> n;
  vector<string> grid(h, string(w, '.'));
  int i = 0, j = 0;
  vector<int> dir = {-1, 0};
  while (true)
  {
    if (grid[i][j] == '.')
    {
      grid[i][j] = '#';
      dir = rot(dir, true);
    }
    else
    {
      grid[i][j] = '.';
      dir = rot(dir, false);
    }
    i = (i + dir[0] + h) % h;
    j = (j + dir[1] + w) % w;
    --n;
    if (n == 0)
      break;
  }
  for (string s : grid)
    cout << s << endl;
}
