#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  cin >> n;
  string s;
  rep(i, n + 1)
  {
    s += "-";
    for (int j = 1; j < 10; j++)
    {
      if (n % j == 0 and i % (n / j) == 0)
      {
        s[i] = j + '0';
        break;
      }
    }
  }
  cout << s << endl;
}
