#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<int> digit;
  while (n > 0)
  {
    digit.push_back(n % 10);
    n /= 10;
  }
  rep(i, digit.size() - 1)
  {
    if (digit[i] >= digit[i + 1])
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
