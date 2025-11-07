#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  ll b;
  cin >> b;
  if (b == 1)
  {
    cout << 1 << endl;
    return 0;
  }
  for (int a = 2; a < 21; a++)
  {
    int x = 0;
    ll y = b;
    while (y % a == 0)
      x++, y /= a;
    if (x == a && y == 1)
    {
      cout << a << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
