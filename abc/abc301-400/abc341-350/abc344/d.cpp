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
  string t;
  int n;
  cin >> t >> n;
  int m = t.size();
  vector dp(n + 1, vector<int>(m + 1, inf));
  dp[0][0] = 0;
  rep(i, 0, n)
  {
    rep(j, 0, m + 1) dp[i + 1][j] = dp[i][j];
    int a;
    cin >> a;
    rep(_, 0, a)
    {
      string s;
      cin >> s;
      int l = s.size();
      rep(j, 0, m + 1)
      {
        if (j + l > m)
          continue;
        bool ok = true;
        rep(k, 0, l) if (t[j + k] != s[k]) ok = false;
        if (ok)
          chmin(dp[i + 1][j + l], dp[i][j] + 1);
      }
    }
  }
  int ans = dp[n][m];
  if (ans == inf)
    ans = -1;
  cout << ans << endl;
}