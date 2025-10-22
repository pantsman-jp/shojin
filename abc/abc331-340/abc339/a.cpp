#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  for (int i = s.size() - 1; -1 < i; i--)
  {
    if (s[i] == '.')
    {
      cout << s.substr(i + 1) << endl;
      return 0;
    }
  }
}
