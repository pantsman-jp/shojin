#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

double dist(ll x1, ll y1, ll x2, ll y2)
{
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
  ll x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double d = dist(x1, y1, x2, y2);
  ll large = max(r1, r2), small = min(r1, r2);
  if (d + small < large)
  {
    cout << 1 << endl;
    return 0;
  }
  if (d + small == large)
  {
    cout << 2 << endl;
    return 0;
  }
  if (d < small + large)
  {
    cout << 3 << endl;
    return 0;
  }
  if (d == small + large)
  {
    cout << 4 << endl;
    return 0;
  }
  if (d > small + large)
  {
    cout << 5 << endl;
    return 0;
  }
}
