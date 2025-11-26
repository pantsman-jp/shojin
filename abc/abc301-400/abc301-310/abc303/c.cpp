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
  int n, m, h, k;
  string s;
  cin >> n >> m >> h >> k >> s;
  set<P> item;
  rep(_, 0, m)
  {
    int x, y;
    cin >> x >> y;
    item.insert(make_pair(x, y));
  }
  int x = 0, y = 0;
  for (char c : s)
  {
    if (c == 'R')
      x++;
    else if (c == 'L')
      x--;
    else if (c == 'U')
      y++;
    else
      y--;
    h--;
    if (h < 0)
    {
      cout << "No" << endl;
      return 0;
    }
    if (item.count({x, y}) != 0 and h < k)
      h = k, item.erase({x, y});
  }
  cout << "Yes" << endl;
}