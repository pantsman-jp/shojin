#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int a, b, d;
  cin >> a >> b >> d;
  while (true)
  {
    cout << a << ' ';
    if (a == b)
      return 0;
    a += d;
  }
}
