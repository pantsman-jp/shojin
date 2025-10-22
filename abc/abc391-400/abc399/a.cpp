#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  string s, t;
  cin >> n >> s >> t;
  int ans = 0;
  rep(i, n)
  {
    if (s[i] != t[i])
      ++ans;
  }
  cout << ans << endl;
}
