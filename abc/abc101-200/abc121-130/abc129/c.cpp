#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
const ll mod = 1e9 + 7;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<bool> broken(n + 1);
  rep(_, 0, m)
  {
    int a;
    cin >> a;
    broken[a] = true;
  }
  vector<ll> dp(n + 1);
  dp[0] = 1;
  if (!broken[1])
    dp[1] = 1;
  rep(i, 2, n + 1)
  {
    if (!broken[i - 1])
      dp[i] += dp[i - 1];
    if (!broken[i - 2])
      dp[i] += dp[i - 2];
    dp[i] %= mod;
  }
  cout << dp[n] << endl;
}