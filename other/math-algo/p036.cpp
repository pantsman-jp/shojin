#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const long double pi = 3.14159265358979323846;

int main()
{
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  long double theta = abs(30.0 * h + 0.5 * m - 6.0 * m);
  theta = min(theta, 360.0 - theta);
  theta = theta * pi / 180.0;
  cout << fixed << setprecision(10) << sqrt(a * a + b * b - 2 * a * b * cos(theta)) << endl;
}
