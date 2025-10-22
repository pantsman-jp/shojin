#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  rep(i, n - 2)
  {
    if (s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C')
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
