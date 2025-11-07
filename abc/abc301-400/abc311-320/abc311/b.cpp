#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, d;
  cin >> n >> d;
  vector<string> s(n);
  rep(i, n) { cin >> s[i]; }
  int ans = 0, tmp = 0;
  rep(j, d)
  {
    bool vacant = true;
    rep(i, n)
    {
      if (s[i][j] == 'x')
        vacant = false;
    }
    if (vacant)
      tmp++;
    else
      tmp = 0;
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
