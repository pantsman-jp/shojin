#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
const int mod = 1e9 + 7;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t = "chokudai";
  cin >> s;
  int n = s.size();
  vector dp(n + 1, vector<int>(9));
  dp[0][0] = 1;
  rep(i, 0, n) rep(j, 0, 9)
  {
    (dp[i + 1][j] += dp[i][j]) %= mod;
    if (j < 9 and s[i] == t[j])
      (dp[i + 1][j + 1] += dp[i][j]) %= mod;
  }
  cout << dp[n][8] << endl;
}