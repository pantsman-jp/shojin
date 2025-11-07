#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int M, D, y, m, d;
  cin >> M >> D >> y >> m >> d;
  if (d == D and m == M)
    cout << y + 1 << ' ' << 1 << ' ' << 1 << endl;
  else if (d == D)
    cout << y << ' ' << m + 1 << ' ' << 1 << endl;
  else
    cout << y << ' ' << m << ' ' << d + 1 << endl;
}
