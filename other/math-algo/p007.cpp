#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  int ans = 0;
  for (int m = 1; m < n + 1; m++)
  {
    if (m % x == 0 or m % y == 0)
      ans++;
  }
  cout << ans << endl;
}
