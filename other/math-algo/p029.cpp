#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int dp[n + 1];
  dp[0] = 1, dp[1] = 1;
  for (int i = 2; i < n + 1; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
  cout << dp[n] << endl;
}
