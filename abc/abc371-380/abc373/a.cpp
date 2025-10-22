#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int ans = 0;
  rep(i, 12)
  {
    string s;
    cin >> s;
    if (i + 1 == (int)s.size())
      ans++;
  }
  cout << ans << endl;
}
