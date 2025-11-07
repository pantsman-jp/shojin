#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  if (s[0] != '<' or s[n - 1] != '>')
  {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 1; i < n - 1; i++)
  {
    if (s[i] != '=')
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
