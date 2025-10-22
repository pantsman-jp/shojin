#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (b < c)
  {
    if (b < a and a < c)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  else
  {
    if (c < a and a < b)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}
