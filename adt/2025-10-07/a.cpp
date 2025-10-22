#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  if (a + b == c or b + c == a or c + a == b or (a == b and b == c))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
