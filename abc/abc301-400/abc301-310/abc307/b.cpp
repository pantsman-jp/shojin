#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool is_pali(string s)
{
  string rev(s);
  reverse(rev.begin(), rev.end());
  return s == rev;
}

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) { cin >> s[i]; }
  rep(i, n)
  {
    rep(j, n)
    {
      if (i == j)
        continue;
      if (is_pali(s[i] + s[j]))
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
