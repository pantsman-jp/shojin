#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int a, b;
  cin >> a >> b;
  if (a % 3 != 0 and a + 1 == b)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
