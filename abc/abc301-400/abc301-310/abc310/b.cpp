#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  vector<vector<int>> f(n);
  for (int i = 0; i < n; i++)
  {
    int c;
    cin >> p[i] >> c;
    f[i].resize(c);
    for (int j = 0; j < c; j++)
      cin >> f[i][j];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;
      if (p[i] >= p[j])
      {
        bool subset = true;
        int p1 = 0, p2 = 0;
        while (p1 < f[i].size() and p2 < f[j].size())
        {
          if (f[i][p1] == f[j][p2])
            p1++, p2++;
          else if (f[i][p1] > f[j][p2])
            p2++;
          else
          {
            subset = false;
            break;
          }
        }
        if (p1 < f[i].size())
          subset = false;
        if (subset)
        {
          if (p[i] > p[j] or f[j].size() > f[i].size())
          {
            cout << "Yes" << endl;
            return 0;
          }
        }
      }
    }
  }
  cout << "No" << endl;
}
