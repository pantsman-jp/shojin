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
// const ll mod = 998244353;
// const ll mod = 1000000007;

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int si, sj, gi, gj;
  rep(i, 0, h) rep(j, 0, w)
  {
    if (s[i][j] == 'S')
      si = i, sj = j;
    if (s[i][j] == 'G')
      gi = i, gj = j;
  }
  int ans = inf;
  vector<vector<P>> moves = {{{0, 1}, {0, -1}}, {{1, 0}, {-1, 0}}};
  rep(p, 0, 2)
  {
    vector dist(h, vector<int>(w, inf));
    dist[si][sj] = 0;
    queue<P> q;
    q.emplace(si, sj);
    while (!q.empty())
    {
      auto [i, j] = q.front();
      q.pop();
      for (auto [di, dj] : moves[(i + j + p) % 2])
      {
        int ni = i + di, nj = j + dj;
        if (out(ni, nj, h, w) or s[ni][nj] == '#')
          continue;
        if (dist[ni][nj] == inf)
        {
          dist[ni][nj] = dist[i][j] + 1;
          q.emplace(ni, nj);
        }
      }
    }
    chmin(ans, dist[gi][gj]);
  }
  if (ans == inf)
    ans = -1;
  cout << ans << endl;
}