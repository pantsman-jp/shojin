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
  int n, k;
  cin >> n >> k;
  vector<int> dp(n + 1);
  dp[0] = 1;
  rep(i, 1, n + 1) dp[i] = min(dp[i - 1] * 2, dp[i - 1] + k);
  cout << dp[n] << endl;
}