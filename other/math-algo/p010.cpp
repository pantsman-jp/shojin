#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

ll fac(int n)
{
  if (n == 0)
    return 1;
  return n * fac(n - 1);
}

int main()
{
  int n;
  cin >> n;
  cout << fac(n) << endl;
}
