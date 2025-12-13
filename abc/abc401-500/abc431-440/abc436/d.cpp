#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, -1, 0, 1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector<vector<P>> warp(26);
  rep(i, 0, h) rep(j, 0, w) if ('a' <= s[i][j] and s[i][j] <= 'z') warp[s[i][j] - 'a'].push_back({i, j});
  vector<vector<int>> dist(h, vector<int>(w, -1));
  queue<P> q;
  dist[0][0] = 0, q.push({0, 0});
  vector<bool> used(26, false);
  while (!q.empty())
  {
    auto [i, j] = q.front();
    q.pop();
    rep(d, 0, 4)
    {
      int ni = i + di[d], nj = j + dj[d];
      if (ni < 0 or ni >= h or nj < 0 or nj >= w or s[ni][nj] == '#' or dist[ni][nj] != -1)
        continue;
      dist[ni][nj] = dist[i][j] + 1, q.push({ni, nj});
    }
    if ('a' <= s[i][j] and s[i][j] <= 'z')
    {
      int c = s[i][j] - 'a';
      if (!used[c])
      {
        used[c] = true;
        for (auto [ni, nj] : warp[c])
        {
          if (dist[ni][nj] != -1)
            continue;
          dist[ni][nj] = dist[i][j] + 1, q.push({ni, nj});
        }
      }
    }
  }
  cout << dist[h - 1][w - 1] << endl;
}