#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  string s;
  cin >> n >> s;
  int t = 0, a = 0;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'T')
      ++t;
    else
      ++a;
  }
  if (t > a)
    cout << 'T' << endl;
  else if (t < a)
    cout << 'A' << endl;
  else
    cout << char('T' + 'A' - s.back()) << endl;
}
