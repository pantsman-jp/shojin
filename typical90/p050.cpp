#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, l;
  cin >> n >> l;
  vector<ll> dp(n + 1, 0);
  dp[0] = 1;
  rep(i, 1, n + 1)
  {
    if (i < l)
      dp[i] = dp[i - 1];
    else
      dp[i] = (dp[i - 1] + dp[i - l]) % 1000000007;
  }
  cout << dp[n] << endl;
}
