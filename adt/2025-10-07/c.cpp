#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  vector<string> a(n);
  rep(i, n) { cin >> a[i]; }
  rep(i, n)
  {
    rep(j, n)
    {
      char ret1 = a[i][j], ret2 = a[j][i];
      if (ret1 == 'W' and (ret2 == 'W' or ret2 == 'D'))
      {
        cout << "incorrect" << endl;
        return 0;
      }
      if (ret1 == 'L' and (ret2 == 'L' or ret2 == 'D'))
      {
        cout << "incorrect" << endl;
        return 0;
      }
      if (ret1 == 'D' and (ret2 == 'W' or ret2 == 'L'))
      {
        cout << "incorrect" << endl;
        return 0;
      }
    }
  }
  cout << "correct" << endl;
}
