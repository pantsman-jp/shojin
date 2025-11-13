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
  vector<int> v(n), c(n), dp(n + 1);
  rep(i, 0, n) cin >> v[i];
  rep(i, 0, n) cin >> c[i];
  dp[0] = 0;
  rep(i, 0, n) dp[i + 1] = max(dp[i], dp[i] + v[i] - c[i]);
  cout << dp[n] << endl;
}