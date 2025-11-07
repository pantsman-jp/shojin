#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int l, r;
  cin >> l >> r;
  if (l + r < 2 and l == 1)
  {
    cout << "Yes" << endl;
    return 0;
  }
  if (l + r < 2 and r == 1)
  {
    cout << "No" << endl;
    return 0;
  }
  else
  {
    cout << "Invalid" << endl;
    return 0;
  }
}
