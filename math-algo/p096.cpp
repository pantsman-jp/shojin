#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> t(n);
  int sum = 0;
  rep(i, 0, n)
  {
    cin >> t[i];
    sum += t[i];
  }
  vector<bool> dp(sum + 1, false);
  dp[0] = true;
  for (int x : t)
    for (int i = sum - x; i >= 0; i--)
      if (dp[i])
        dp[i + x] = true;
  int ans = sum;
  rep(i, 0, sum + 1)
  {
    if (dp[i])
      ans = min(ans, max(i, sum - i));
  }
  cout << ans << endl;
}