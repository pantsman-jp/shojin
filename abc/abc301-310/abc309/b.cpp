#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, n)
  {
    string s;
    cin >> s;
    rep(j, n)
    {
      if (s[j] == '0')
        a[i][j] = 0;
      else
        a[i][j] = 1;
    }
  }
  vector<vector<int>> ans(n, vector<int>(n));
  rep(i, n)
  {
    rep(j, n)
    {
      if (i == 0 or j == 0 or i == n - 1 or j == n - 1)
      {
        if (i == 0 and j < n - 1)
          ans[i][j + 1] = a[i][j];
        if (i < n - 1 and j == n - 1)
          ans[i + 1][j] = a[i][j];
        if (i == n - 1 and j > 0)
          ans[i][j - 1] = a[i][j];
        if (i > 0 and j == 0)
          ans[i - 1][j] = a[i][j];
      }
      else
        ans[i][j] = a[i][j];
    }
  }
  rep(i, n)
  {
    rep(j, n) { cout << ans[i][j]; }
    cout << endl;
  }
}
