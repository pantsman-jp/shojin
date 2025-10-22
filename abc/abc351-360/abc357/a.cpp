#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, m;
  cin >> n >> m;
  int ans = 0;
  rep(_, n)
  {
    int h;
    cin >> h;
    if (m < h)
    {
      cout << ans << endl;
      return 0;
    }
    else
    {
      m -= h;
      ans++;
    }
  }
  cout << ans << endl;
}
