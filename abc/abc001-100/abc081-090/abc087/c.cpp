#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector a(2, vector<int>(n));
  rep(i, 0, 2) rep(j, 0, n) cin >> a[i][j];
  vector dp(2, vector<int>(n));
  dp[0][0] = a[0][0];
  dp[1][0] = a[0][0] + a[1][0];
  rep(j, 1, n) dp[0][j] = dp[0][j - 1] + a[0][j];
  rep(j, 1, n) dp[1][j] = max(dp[0][j], dp[1][j - 1]) + a[1][j];
  cout << dp[1][n - 1] << endl;
}