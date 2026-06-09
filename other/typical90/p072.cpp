#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

int h, w;
vector<string> c;
vector<vector<bool>> seen;

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int dfs(int sx, int sy, int px, int py, int dist)
{
  int ans = -inf;
  rep(d, 0, 4)
  {
    int nx = px + di[d], ny = py + dj[d];
    if (out(nx, ny, h, w) or c[nx][ny] == '#')
      continue;
    if (nx == sx and ny == sy)
    {
      if (dist >= 3)
        chmax(ans, dist);
      continue;
    }
    if (seen[nx][ny])
      continue;
    seen[nx][ny] = true;
    int res = dfs(sx, sy, nx, ny, dist + 1);
    if (res != -inf)
      chmax(ans, res);
    seen[nx][ny] = false;
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  c.resize(h), seen.resize(h, vector<bool>(w, false));
  rep(i, 0, h) cin >> c[i];
  int ans = -1;
  rep(i, 0, h) rep(j, 0, w)
  {
    if (c[i][j] == '#')
      continue;
    seen[i][j] = true;
    chmax(ans, dfs(i, j, i, j, 1));
    seen[i][j] = false;
  }
  cout << ans << endl;
}