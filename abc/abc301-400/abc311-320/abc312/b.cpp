#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool check(vector<string> grid, int i, int j)
{
  rep(dy, 3)
  {
    rep(dx, 3)
    {
      if (grid[i + dy][j + dx] != '#')
        return false;
    }
  }
  for (int y = i + 6; y < i + 9; y++)
  {
    for (int x = j + 6; x < j + 9; x++)
    {
      if (grid[y][x] != '#')
        return false;
    }
  }
  rep(dy, 4)
  {
    if (grid[i + dy][j + 3] != '.')
      return false;
  }
  rep(dx, 3)
  {
    if (grid[i + 3][j + dx] != '.')
      return false;
  }
  for (int y = i + 5; y < i + 9; y++)
  {
    if (grid[y][j + 5] != '.')
      return false;
  }
  for (int x = j + 6; x < j + 9; x++)
  {
    if (grid[i + 5][x] != '.')
      return false;
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  rep(i, n) { cin >> grid[i]; }
  rep(i, n - 8)
  {
    rep(j, m - 8)
    {
      if (check(grid, i, j))
        cout << i + 1 << ' ' << j + 1 << endl;
    }
  }
}
