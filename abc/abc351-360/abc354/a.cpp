#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int h;
  cin >> h;
  int ans = 1, plant = 1, diff = 2;
  while (true)
  {
    if (plant > h)
    {
      cout << ans << endl;
      return 0;
    }
    ans++;
    plant += diff;
    diff *= 2;
  }
}
