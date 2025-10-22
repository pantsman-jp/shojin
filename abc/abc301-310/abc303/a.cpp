#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  string s, t;
  cin >> n >> s >> t;
  rep(i, n)
  {
    if (!(s[i] == t[i] or (s[i] == '0' and t[i] == 'o') or (s[i] == 'o' and t[i] == '0') or (s[i] == 'l' and t[i] == '1') or (s[i] == '1' and t[i] == 'l')))
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
