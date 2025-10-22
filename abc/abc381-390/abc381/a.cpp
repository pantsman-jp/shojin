#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  if (n % 2 == 0)
  {
    cout << "No" << endl;
    return 0;
  }
  rep(i, (n + 1) / 2 - 1)
  {
    if (s[i] != '1')
    {
      cout << "No" << endl;
      return 0;
    }
  }
  if (s[(n + 1) / 2 - 1] != '/')
  {
    cout << "No" << endl;
    return 0;
  }
  for (int i = (n + 1) / 2; i < n; ++i)
  {
    if (s[i] != '2')
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
