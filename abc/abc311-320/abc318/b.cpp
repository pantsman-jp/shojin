#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<vector<int>> grid(100, vector<int>(100, 0));
  rep(_, n)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i < b; i++)
      for (int j = c; j < d; j++)
        grid[i][j] = 1;
  }
  int ans = 0;
  rep(i, 100)
  {
    rep(j, 100)
    {
      ans += grid[i][j];
    }
  }
  cout << ans << endl;
}
