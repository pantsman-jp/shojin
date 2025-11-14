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
  vector<bool> dp(n + 1);
  dp[0] = true;
  rep(i, 0, n + 1)
  {
    if (!dp[i])
      continue;
    if (i + 4 <= n)
      dp[i + 4] = true;
    if (i + 7 <= n)
      dp[i + 7] = true;
  }
  if (dp[n])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}