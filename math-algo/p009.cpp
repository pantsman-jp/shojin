#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, s;
  cin >> n >> s;
  vector<int> a(n + 1);
  for (int i = 1; i < n + 1; i++)
    cin >> a[i];
  vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
  dp[0][0] = true;
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 0; j < s + 1; j++)
    {
      if (!dp[i - 1][j])
        continue;
      dp[i][j] = true;
      if (j + a[i] <= s)
        dp[i][j + a[i]] = true;
    }
  }
  if (dp[n][s])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
