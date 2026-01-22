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

int hand(char c)
{
  if (c == 'R')
    return 0;
  if (c == 'S')
    return 1;
  return 2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  vector dp(n + 1, vector<int>(3, -1));
  int aoki0 = hand(s[0]);
  rep(j, 0, 3)
  {
    if (j == (aoki0 + 1) % 3)
      continue;
    dp[1][j] = (j == (aoki0 + 2) % 3 ? 1 : 0);
  }
  rep(i, 1, n)
  {
    int aoki = hand(s[i]);
    rep(j, 0, 3)
    {
      if (j == (aoki + 1) % 3)
        continue;
      int win = (j == (aoki + 2) % 3 ? 1 : 0);
      rep(k, 0, 3)
      {
        if (dp[i][k] == -1 or j == k)
          continue;
        chmax(dp[i + 1][j], dp[i][k] + win);
      }
    }
  }
  int ans = 0;
  rep(j, 0, 3) chmax(ans, dp[n][j]);
  cout << ans << endl;
}