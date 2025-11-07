#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  char c1, c2;
  string s;
  cin >> n >> c1 >> c2 >> s;
  string ans;
  for (char c : s)
  {
    if (c == c1)
      ans += c;
    else
      ans += c2;
  }
  cout << ans << endl;
}
