#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;
  if (a == b)
  {
    cout << -1 << endl;
    return 0;
  }
  cout << 6 - (a + b) << endl;
}
