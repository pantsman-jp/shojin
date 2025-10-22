#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, c;
  cin >> n >> c;
  vector<int> t(n);
  rep(i, n) { cin >> t[i]; }
  int prev = t[0], ans = 1;
  for (int i = 1; i < n; ++i)
  {
    if (t[i] - prev >= c)
    {
      ++ans;
      prev = t[i];
    }
  }
  cout << ans << endl;
}
