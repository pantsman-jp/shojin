#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c;
  cin >> a >> b >> c;
  if (c == 1)
  {
    if (a < 1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }
  __int128 x = 1;
  rep(i, 0, b)
  {
    x *= c;
    if (x > a)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}