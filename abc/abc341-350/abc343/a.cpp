#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;
  int sum = a + b;
  rep(ans, 10)
  {
    if (ans != sum)
    {
      cout << ans << endl;
      return 0;
    }
  }
}
