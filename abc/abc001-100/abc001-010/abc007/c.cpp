#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

int h, w;
vector<string> c;
vector<vector<bool>> seen;
vector<vector<int>> dist;

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

void bfs(int i, int j)
{
  queue<P> q;
  q.push({i, j});
  seen[i][j] = true;
  while (!q.empty())
  {
    auto [u, v] = q.front();
    q.pop();
    rep(d, 0, 4)
    {
      int ni = u + di[d], nj = v + dj[d];
      if (out(ni, nj, h, w) or c[ni][nj] == '#' or seen[ni][nj])
        continue;
      seen[ni][nj] = true;
      dist[ni][nj] = dist[u][v] + 1;
      q.push({ni, nj});
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  int sy, sx, gy, gx;
  cin >> sy >> sx >> gy >> gx;
  sy--, sx--, gy--, gx--;
  c.resize(h);
  rep(i, 0, h) cin >> c[i];
  seen.assign(h, vector<bool>(w, false));
  dist.assign(h, vector<int>(w, 0));
  bfs(sy, sx);
  cout << dist[gy][gx] << endl;
}