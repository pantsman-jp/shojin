#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  double x;
  cin >> x;
  if (38.0 <= x)
  {
    cout << 1 << endl;
    return 0;
  }
  if (37.5 <= x && x < 38.0)
  {
    cout << 2 << endl;
    return 0;
  }
  cout << 3 << endl;
  return 0;
}
