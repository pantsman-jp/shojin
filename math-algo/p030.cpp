#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int N, W;
  cin >> N >> W;
  vector<ll> w(N + 1), v(N + 1);
  for (int i = 1; i < N + 1; i++)
    cin >> w[i] >> v[i];
  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, -inf));
  dp[0][0] = 0;
  for (int i = 1; i < N + 1; i++)
  {
    rep(j, W + 1)
    {
      if (j < w[i])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
    }
  }
  cout << *max_element(dp[N].begin(), dp[N].end()) << endl;
}
