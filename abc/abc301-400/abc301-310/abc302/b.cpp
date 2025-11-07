#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, m, x, y;
  cin >> n >> m;
  vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1}, dy = {-1, 0, 1, -1, 1, -1, 0, 1};
  string str;
  vector<string> s(n);
  rep(i, n) { cin >> s[i]; }
  rep(i, n)
  {
    rep(j, m)
    {
      rep(k, 8)
      {
        str = "";
        rep(t, 5)
        {
          x = i + t * dx[k], y = j + t * dy[k];
          if (x < 0 or x >= n or y < 0 or y >= m)
            break;
          str += s[x][y];
        }
        if (str == "snuke")
        {
          rep(t, 5)
          {
            x = i + t * dx[k] + 1, y = j + t * dy[k] + 1;
            cout << x << " " << y << endl;
          }
        }
      }
    }
  }
}
