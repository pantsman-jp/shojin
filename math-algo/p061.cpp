#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  ll n;
  cin >> n;
  for (int m = 1; m < 61; m++)
  {
    if (n == (1LL << m) - 1)
    {
      cout << "Second" << endl;
      return 0;
    }
  }
  cout << "First" << endl;
}
