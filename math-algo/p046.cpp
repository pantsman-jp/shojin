#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;

vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
using pint = pair<int, int>;

int main()
{
  int r, c, sx, sy, tx, gy;
  cin >> r >> c >> sy >> sx >> tx >> gy;
  --sx, --sy, --tx, --gy;
  vector<string> field(r);
  rep(i, r) { cin >> field[i]; }
  queue<pint> q;
  vector<vector<int>> dist(r, vector<int>(c, -1));
  q.push({sx, sy});
  dist[sx][sy] = 0;
  while (!q.empty())
  {
    auto [x, y] = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir)
    {
      int x2 = x + dx[dir];
      int y2 = y + dy[dir];
      if (x2 < 0 or x2 >= r or y2 < 0 or y2 >= c)
        continue;
      if (field[x2][y2] == '#')
        continue;
      if (dist[x2][y2] != -1)
        continue;
      q.push({x2, y2});
      dist[x2][y2] = dist[x][y] + 1;
    }
  }
  cout << dist[tx][gy] << endl;
}