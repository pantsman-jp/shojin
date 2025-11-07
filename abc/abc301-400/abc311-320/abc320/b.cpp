#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool is_pali(string s)
{
  string revs = s;
  reverse(revs.begin(), revs.end());
  return s == revs;
}

int main()
{
  string s;
  cin >> s;
  int n = s.size();
  for (int len = n; 0 < len; len--)
  {
    rep(i, n)
    {
      if (i + len > n)
        break;
      else if (is_pali(s.substr(i, len)))
      {
        cout << len << endl;
        return 0;
      }
    }
  }
}
