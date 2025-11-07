#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  int ctz = 0;
  while (true)
  {
    if (n % 2 != 0)
    {
      cout << ctz << endl;
      return 0;
    }
    n /= 2;
    ctz++;
  }
}
