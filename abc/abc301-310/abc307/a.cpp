#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  int ans = 0, day = 0;
  rep(_, n * 7)
  {
    int a;
    cin >> a;
    ans += a, day++;
    if (day == 7)
    {
      cout << ans << ' ';
      ans = 0, day = 0;
    }
  }
  cout << endl;
}
