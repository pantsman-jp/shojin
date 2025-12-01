#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int ans = -1, len = 0;
  rep(i, 0, n)
  {
    if (s[i] == 'o')
      len++, ans = max(ans, len);
    else
      len = 0;
  }
  if (ans == n)
    ans = -1;
  cout << ans << endl;
}