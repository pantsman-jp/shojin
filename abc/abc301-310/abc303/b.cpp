#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m, vector<int>(n));
  rep(i, m)
  {
    rep(j, n) { cin >> a[i][j]; }
  }
  vector<vector<bool>> discord(n, vector<bool>(n, true));
  rep(i, n) discord[i][i] = false;
  rep(i, m)
  {
    rep(j, n - 1)
    {
      int x = a[i][j] - 1, y = a[i][j + 1] - 1;
      discord[x][y] = discord[y][x] = false;
    }
  }
  int ans = 0;
  rep(i, n)
  {
    rep(j, i)
    {
      if (discord[i][j])
        ans++;
    }
  }
  cout << ans << endl;
}
