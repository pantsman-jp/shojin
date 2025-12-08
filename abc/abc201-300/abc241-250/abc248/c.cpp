#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
const int mod = 998244353;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1));
  dp[0][0] = 1;
  rep(x, 1, n + 1) rep(y, 0, k + 1)
  {
    int now = 0;
    rep(i, 1, m + 1) if (y - i >= 0) now += dp[x - 1][y - i], now %= mod;
    dp[x][y] = now;
  }
  int ans = 0;
  rep(y, 0, k + 1) ans += dp[n][y], ans %= mod;
  cout << ans << endl;
}