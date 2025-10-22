#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  int sum = a + b;
  for (int ans = 1; ans < n + 1; ans++)
  {
    int c;
    cin >> c;
    if (sum == c)
    {
      cout << ans << endl;
      return 0;
    }
  }
}
