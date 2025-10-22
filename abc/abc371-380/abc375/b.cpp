#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int x = 0, y = 0;
  double ans = 0.0;
  for (int i = 0; i < n; i++)
  {
    int X, Y;
    cin >> X >> Y;
    ans += sqrt((x - X) * (x - X) + (y - Y) * (y - Y));
    x = X;
    y = Y;
  }
  ans += sqrt(x * x + y * y);
  cout << ans << endl;
}
