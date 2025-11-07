#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (60 * a + b > 60 * c + d)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
