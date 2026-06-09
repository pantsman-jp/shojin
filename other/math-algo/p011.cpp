#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++)
  {
    bool prime = true;
    for (int j = 2; j * j <= i; j++)
    {
      if (i % j == 0)
      {
        prime = false;
        break;
      }
    }
    if (prime)
      cout << i << ' ';
  }
  cout << endl;
}
