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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector dpl_min(n + 1, vector<int>(2, inf));
  vector dpl_max(n + 1, vector<int>(2, -inf));
  dpl_min[0][0] = dpl_max[0][0] = 0;
  rep(i, 0, n) rep(j, 0, 2)
  {
    if (dpl_max[i][j] < 0)
      continue;
    if (s[i] == '.' or s[i] == '?')
    {
      chmin(dpl_min[i + 1][0], dpl_min[i][j]);
      chmax(dpl_max[i + 1][0], dpl_max[i][j]);
    }
    if ((s[i] == 'o' or s[i] == '?') and j == 0)
    {
      chmin(dpl_min[i + 1][1], dpl_min[i][j] + 1);
      chmax(dpl_max[i + 1][1], dpl_max[i][j] + 1);
    }
  }
  vector dpr_min(n + 1, vector<int>(2, inf));
  vector dpr_max(n + 1, vector<int>(2, -inf));
  dpr_min[n][0] = dpr_max[n][0] = 0;
  rrep(i, n, 0) rep(j, 0, 2)
  {
    if (dpr_max[i + 1][j] < 0)
      continue;
    if (s[i] == '.' or s[i] == '?')
    {
      chmin(dpr_min[i][0], dpr_min[i + 1][j]);
      chmax(dpr_max[i][0], dpr_max[i + 1][j]);
    }
    if ((s[i] == 'o' or s[i] == '?') and j == 0)
    {
      chmin(dpr_min[i][1], dpr_min[i + 1][j] + 1);
      chmax(dpr_max[i][1], dpr_max[i + 1][j] + 1);
    }
  }
  auto ok = [&](int lmin, int lmax, int rmin, int rmax, int need)
  {
    return lmin + rmin <= need and need <= lmax + rmax;
  };
  rep(i, 0, n)
  {
    bool o = false, dot = false;
    if (s[i] == 'o' or s[i] == '?')
    {
      if (ok(dpl_min[i][0], dpl_max[i][0], dpr_min[i + 1][0], dpr_max[i + 1][0], k - 1))
        o = true;
    }
    if (s[i] == '.' or s[i] == '?')
    {
      int lmin = min(dpl_min[i][0], dpl_min[i][1]);
      int lmax = max(dpl_max[i][0], dpl_max[i][1]);
      int rmin = min(dpr_min[i + 1][0], dpr_min[i + 1][1]);
      int rmax = max(dpr_max[i + 1][0], dpr_max[i + 1][1]);
      if (ok(lmin, lmax, rmin, rmax, k))
        dot = true;
    }
    if (o and dot)
      cout << '?';
    else if (o)
      cout << 'o';
    else
      cout << '.';
  }
  cout << endl;
}