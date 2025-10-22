#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  vector<bool> dp(n + 1, false);
  dp[0] = true;
  for (int i = 0; i < n + 1; i++)
  {
    if (dp[i])
      for (string t : {"dream", "dreamer", "erase", "eraser"})
        if (s.substr(i, t.size()) == t)
          dp[i + t.size()] = true;
  }
  if (dp[n])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}