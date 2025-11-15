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
  string s;
  int t;
  cin >> s >> t;
  int y = 0, x = 0, cnt = 0;
  for (char c : s)
  {
    if (c == 'L')
      x++;
    if (c == 'R')
      x--;
    if (c == 'U')
      y--;
    if (c == 'D')
      y++;
    if (c == '?')
      cnt++;
  }
  int dist = abs(x) + abs(y);
  if (t == 1)
    cout << dist + cnt << endl;
  if (t == 2)
  {
    int ans = dist;
    rep(i, 0, cnt)
    {
      if (ans == 0)
        ans++;
      else
        ans -= 1;
    }
    cout << ans << endl;
  }
}