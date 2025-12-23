#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

const vector<string> strs = {"dream", "dreamer", "erase", "eraser"};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  vector<bool> dp(n + 1, false);
  dp[0] = true;
  rep(i, 1, n + 1)
  {
    for (string str : strs)
    {
      if (i >= str.size() and
          dp[i - str.size()] and
          s.substr(i - str.size(), str.size()) == str)
        dp[i] = true;
    }
  }
  if (dp[n])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}