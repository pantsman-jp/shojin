#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int x, y;
  cin >> x >> y;
  if ((x < y and y - x < 3) or (y < x and x - y < 4))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
