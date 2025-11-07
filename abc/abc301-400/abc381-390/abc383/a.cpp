#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> t(n), v(n);
  for (int i = 0; i < n; ++i)
    cin >> t[i] >> v[i];
  int ans = 0, prev = 0;
  for (int i = 0; i < n; i++)
  {
    ans = max(0, ans - (t[i] - prev));
    ans += v[i];
    prev = t[i];
  }
  cout << ans << endl;
}
