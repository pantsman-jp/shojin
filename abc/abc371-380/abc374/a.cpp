#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  string s;
  cin >> s;
  int n = (int)s.size();
  if (s[n - 3] == 's' and s[n - 2] == 'a' and s[n - 1] == 'n')
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
