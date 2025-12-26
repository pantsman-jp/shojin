#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
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
// const ll mod =;

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, 1, 0, -1};

int h, w, q;
vector<vector<bool>> red;
dsu uf({});

int id(int r, int c)
{
  return r * w + c;
}

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

void solve()
{
  int t;
  cin >> t;
  if (t == 1)
  {
    int r, c;
    cin >> r >> c;
    r--, c--;
    red[r][c] = true;
    int v = id(r, c);
    rep(d, 0, 4)
    {
      int nr = r + di[d], nc = c + dj[d];
      if (!out(nr, nc, h, w) and red[nr][nc])
        uf.merge(v, id(nr, nc));
    }
  }
  else
  {
    int ra, ca, rb, cb;
    cin >> ra >> ca >> rb >> cb;
    ra--, ca--, rb--, cb--;
    bool ok = false;
    if (red[ra][ca] and red[rb][cb])
      ok = uf.same(id(ra, ca), id(rb, cb));
    yn(ok);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w >> q;
  red.assign(h, vector<bool>(w, false));
  uf = dsu(h * w);
  rep(_, 0, q) solve();
}