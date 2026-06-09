#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  ll bax = ax - bx, bay = ay - by;
  ll bcx = cx - bx, bcy = cy - by;
  ll cax = ax - cx, cay = ay - cy;
  ll cbx = bx - cx, cby = by - cy;
  int pattern = 2;
  if (bax * bcx + bay * bcy < 0)
    pattern = 1;
  else if (cax * cbx + cay * cby < 0)
    pattern = 3;
  double ans = 0.0;
  if (pattern == 1)
    ans = sqrt(bax * bax + bay * bay);
  else if (pattern == 3)
    ans = sqrt(cax * cax + cay * cay);
  else
    ans = (double)abs(bax * cay - bay * cax) / sqrt(bcx * bcx + bcy * bcy);
  cout << fixed << setprecision(10) << ans << endl;
}
