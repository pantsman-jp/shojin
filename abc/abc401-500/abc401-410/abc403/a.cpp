#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, ans = 0;
  cin >> n;
  bool odd = true;
  rep(i, n)
  {
    int a;
    cin >> a;
    if (odd)
    {
      ans += a;
      odd = !odd;
    }
    else
      odd = !odd;
  }
  cout << ans << endl;
}
