#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  if (min(x, y) <= z and z <= max(x, y))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
