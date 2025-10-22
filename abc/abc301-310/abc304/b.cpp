#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  if (n < 1000)
    cout << n << endl;
  if (1000 <= n and n < 10000)
    cout << n - n % 10 << endl;
  if (10000 <= n and n < 100000)
    cout << n - n % 100 << endl;
  if (100000 <= n and n < 1000000)
    cout << n - n % 1000 << endl;
  if (1000000 <= n and n < 10000000)
    cout << n - n % 10000 << endl;
  if (10000000 <= n and n < 100000000)
    cout << n - n % 100000 << endl;
  if (100000000 <= n and n < 1000000000)
    cout << n - n % 1000000 << endl;
}
