#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  string s;
  cin >> s;
  int ans = 0;
  for (char c : s)
    if (c == '1')
      ans++;
  cout << ans << endl;
}