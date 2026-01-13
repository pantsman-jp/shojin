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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t)
  {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    vector<int> orig(h);
    rep(i, 0, h)
    {
      int m = 0;
      rep(j, 0, w) if (s[i][j] == '#') m |= (1 << j);
      orig[i] = m;
    }
    int n = 1 << w;
    vector dp(h + 1, vector<int>(n, inf));
    rep(s0, 0, n) dp[1][s0] = __builtin_popcount(orig[0] & (~s0));
    rep(i, 2, h + 1)
    {
      rep(p, 0, n)
      {
        if (dp[i - 1][p] == inf)
          continue;
        rep(s1, 0, n)
        {
          bool ok = true;
          rep(j, 0, w - 1)
          {
            if ((p & (1 << j)) && (p & (1 << (j + 1))) and (s1 & (1 << j)) && (s1 & (1 << (j + 1))))
            {
              ok = false;
              break;
            }
          }
          if (!ok)
            continue;
          chmin(dp[i][s1], dp[i - 1][p] + __builtin_popcount(orig[i - 1] & (~s1)));
        }
      }
    }
    int ans = inf;
    rep(j, 0, n) chmin(ans, dp[h][j]);
    cout << ans << endl;
  }
}