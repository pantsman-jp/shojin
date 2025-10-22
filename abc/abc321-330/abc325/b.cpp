#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> w(n), x(n);
  rep(i, n) { cin >> w[i] >> x[i]; }
  int ans = 0;
  for (int l = 0; l < 24; l++)
  {
    int tmp = 0;
    rep(i, n)
    {
      int local = (l + x[i]) % 24;
      if (9 <= local and local < 18)
        tmp += w[i];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}
