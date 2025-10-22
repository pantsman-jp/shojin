#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  string s;
  cin >> s;
  int l = s.size();
  int n = (l + 1) / 2 - 1;
  rep(i, l)
  {
    if (i == n)
      continue;
    else
      cout << s[i];
  }
  cout << endl;
}
