#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int y;
  cin >> y;
  if (y % 4 != 0 or (y % 100 == 0 and y % 400 != 0))
    cout << 365 << endl;
  if ((y % 4 == 0 and y % 100 != 0) or y % 400 == 0)
    cout << 366 << endl;
}
