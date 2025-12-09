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
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];
  vector<vector<bool>> dp(n + 1, vector<bool>(x + 1));
  dp[0][0] = true;
  rep(i, 0, n) rep(j, 0, x + 1)
  {
    if (j - a[i] >= 0 and dp[i][j - a[i]])
      dp[i + 1][j] = true;
    if (j - b[i] >= 0 and dp[i][j - b[i]])
      dp[i + 1][j] = true;
  }
  if (dp[n][x])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}