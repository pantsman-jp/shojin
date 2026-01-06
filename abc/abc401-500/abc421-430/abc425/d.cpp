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
  vector step(h, vector<int>(w, inf));
  queue<P> q;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#') step[i][j] = 0, q.emplace(i, j);
  int ans = 0;
  while (q.size() != 0)
  {
    ans++;
    auto [i, j] = q.front();
    q.pop();
    int si = step[i][j];
    rep(v, 0, 4)
    {
      int ni = i + di[v], nj = j + dj[v];
      if (out(ni, nj, h, w) or step[ni][nj] != inf)
        continue;
      int cnt = 0;
      rep(v2, 0, 4)
      {
        int mi = ni + di[v2], mj = nj + dj[v2];
        if (out(mi, mj, h, w))
          continue;
        if (step[mi][mj] <= si)
          cnt++;
      }
      if (cnt == 1)
      {
        step[ni][nj] = si + 1;
        q.emplace(ni, nj);
      }
    }
  }
  cout << ans << endl;
}