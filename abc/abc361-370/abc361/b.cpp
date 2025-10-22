#include <iostream>
#include <vector>
using namespace std;

bool overlap(int l1, int r1, int l2, int r2)
{
  return !(r2 <= l1 or r1 <= l2);
}

int main()
{
  int a, b, c, d, e, f, g, h, i, j, k, l;
  cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
  if (overlap(a, d, g, j) and overlap(b, e, h, k) and overlap(c, f, i, l))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
