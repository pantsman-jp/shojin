#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const int inf = 1e9;

const vector<int> di = {-1, 0, 1, 0}, dj = {0, -1, 0, 1};

int main()
{
  int h, w, D;
  cin >> h >> w >> D;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector<vector<int>> dist(h, vector<int>(w, inf));
  queue<P> q;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == 'H') dist[i][j] = 0, q.emplace(i, j);
  while (!q.empty())
  {
    auto [i, j] = q.front();
    q.pop();
    int cd = dist[i][j];
    rep(v, 0, 4)
    {
      int ni = i + di[v], nj = j + dj[v];
      if (ni < 0 or nj < 0 or ni >= h or nj >= w)
        continue;
      if (s[ni][nj] == '#' or dist[ni][nj] != inf)
        continue;
      dist[ni][nj] = cd + 1;
      q.emplace(ni, nj);
    }
  }
  int ans = 0;
  rep(i, 0, h) rep(j, 0, w) if (dist[i][j] <= D) ans++;
  cout << ans << endl;
}
