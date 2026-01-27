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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int ans = inf;
  rep(i, 0, h)
  {
    int cx = 0, cd = 0;
    rep(j, 0, w)
    {
      if (s[i][j] == 'x')
        cx++;
      if (s[i][j] == '.')
        cd++;
      if (j >= k)
      {
        if (s[i][j - k] == 'x')
          cx--;
        if (s[i][j - k] == '.')
          cd--;
      }
      if (j >= k - 1 and cx == 0)
        chmin(ans, cd);
    }
  }
  rep(j, 0, w)
  {
    int cx = 0, cd = 0;
    rep(i, 0, h)
    {
      if (s[i][j] == 'x')
        cx++;
      if (s[i][j] == '.')
        cd++;
      if (i >= k)
      {
        if (s[i - k][j] == 'x')
          cx--;
        if (s[i - k][j] == '.')
          cd--;
      }
      if (i >= k - 1 and cx == 0)
        chmin(ans, cd);
    }
  }
  if (ans == inf)
    cout << -1 << endl;
  else
    cout << ans << endl;
}