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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  queue<P> q;
  vector seen(h, vector<bool>(w));
  vector dist(h, vector<int>(w, inf));
  rep(i, 0, h) rep(j, 0, w)
  {
    if (s[i][j] == 'E')
    {
      seen[i][j] = true;
      dist[i][j] = 0;
      q.push({i, j});
    }
  }
  while (!q.empty())
  {
    auto [i, j] = q.front();
    q.pop();
    rep(d, 0, 4)
    {
      int ni = i + di[d], nj = j + dj[d];
      if (!out(ni, nj, h, w) and !seen[ni][nj] and s[ni][nj] != '#')
      {
        seen[ni][nj] = true;
        dist[ni][nj] = dist[i][j] + 1;
        q.push({ni, nj});
      }
    }
  }
  vector ans = s;
  string arrow = "^>v<";
  rep(i, 0, h) rep(j, 0, w)
  {
    if (s[i][j] == '.')
    {
      rep(d, 0, 4)
      {
        int ni = i + di[d], nj = j + dj[d];
        if (!out(ni, nj, h, w) and dist[ni][nj] == dist[i][j] - 1)
        {
          ans[i][j] = arrow[d];
          break;
        }
      }
    }
  }
  for (string t : ans)
    cout << t << endl;
}