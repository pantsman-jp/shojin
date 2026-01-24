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
  vector end(h, vector<bool>(w));
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#')
  {
    end[i][j] = true;
    rep(v, 0, 4)
    {
      int ni = i + di[v], nj = j + dj[v];
      if (out(ni, nj, h, w))
        continue;
      end[ni][nj] = true;
    }
  }
  vector seen(h, vector<bool>(w));
  vector last(h, vector<int>(w));
  int tm = 0, ans = 1;
  rep(r, 0, h) rep(c, 0, w) if (!end[r][c])
  {
    if (seen[r][c])
      continue;
    tm++;
    int cnt = 0;
    queue<P> q;
    q.emplace(r, c);
    seen[r][c] = true;
    while (!q.empty())
    {
      auto [i, j] = q.front();
      q.pop();
      cnt++;
      rep(v, 0, 4)
      {
        int ni = i + di[v], nj = j + dj[v];
        if (out(ni, nj, h, w) or seen[ni][nj])
          continue;
        if (end[ni][nj])
        {
          if (last[ni][nj] != tm)
            cnt++, last[ni][nj] = tm;
          continue;
        }
        q.emplace(ni, nj);
        seen[ni][nj] = true;
      }
    }
    chmax(ans, cnt);
  }
  cout << ans << endl;
}