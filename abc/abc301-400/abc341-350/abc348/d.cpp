#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
const ld pi = acosl(-1.0L);
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
  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];
  int si, sj;
  rep(i, 0, h) rep(j, 0, w) if (a[i][j] == 'S') si = i, sj = j;
  int n;
  cin >> n;
  map<P, int> med;
  rep(_, 0, n)
  {
    int r, c, e;
    cin >> r >> c >> e;
    med[{r - 1, c - 1}] = e;
  }
  queue<P> q;
  vector best(h, vector<int>(w, -inf));
  int hp = 0;
  if (med.count({si, sj}) > 0)
    hp = med[{si, sj}];
  best[si][sj] = hp;
  q.push({si, sj});
  while (!q.empty())
  {
    auto [i, j] = q.front();
    q.pop();
    int hp = best[i][j];
    if (a[i][j] == 'T')
    {
      yn(true);
      return 0;
    }
    rep(d, 0, 4)
    {
      int ni = i + di[d], nj = j + dj[d];
      if (out(ni, nj, h, w) or a[ni][nj] == '#' or hp == 0)
        continue;
      int nhp = hp - 1;
      if (med.count({ni, nj}) > 0)
        nhp = max(nhp, med[{ni, nj}]);
      if (nhp <= best[ni][nj])
        continue;
      best[ni][nj] = nhp;
      q.push({ni, nj});
    }
  }
  yn(false);
}