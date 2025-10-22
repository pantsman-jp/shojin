#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, x;
  cin >> n >> x;
  int ans = 0;
  rep(_, n)
  {
    int s;
    cin >> s;
    if (s <= x)
      ans += s;
  }
  cout << ans << endl;
}
