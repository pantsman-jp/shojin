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
  int n;
  cin >> n;
  vector<vector<int>> dp(n + 1, vector<int>(10));
  rep(i, 1, 10) dp[1][i] = 1;
  rep(d, 2, n + 1) rep(i, 1, 10) rep(j, max(1, i - 1), min(9, i + 1) + 1) dp[d][j] += dp[d - 1][i], dp[d][j] %= mod;
  int ans = 0;
  rep(i, 1, 10) ans += dp[n][i], ans %= mod;
  cout << ans << endl;
}