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

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w, rs, cs, rt, ct;
  cin >> h >> w >> rs >> cs >> rt >> ct;
  rs--, cs--, rt--, ct--;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(4, inf)));
  deque<tuple<int, int, int>> q;
  rep(d, 0, 4)
  {
    dist[rs][cs][d] = 0;
    q.emplace_back(rs, cs, d);
  }
  while (!q.empty())
  {
    auto [r, c, d] = q.front();
    q.pop_front();
    rep(nd, 0, 4)
    {
      int nr = r + di[nd], nc = c + dj[nd];
      if (out(nr, nc, h, w) or s[nr][nc] == '#')
        continue;
      int cost = dist[r][c][d];
      if (d != nd)
        cost++;
      if (cost < dist[nr][nc][nd])
      {
        dist[nr][nc][nd] = cost;
        if (d == nd)
          q.emplace_front(nr, nc, nd);
        else
          q.emplace_back(nr, nc, nd);
      }
    }
  }
  int ans = inf;
  rep(d, 0, 4) chmin(ans, dist[rt][ct][d]);
  cout << ans << endl;
}