#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int h, w;

void move(int &i, int &j, char c)
{
  if (c == 'R')
    j++;
  else if (c == 'L')
    j--;
  else if (c == 'U')
    i--;
  else if (c == 'D')
    i++;
}

bool is_legal(int i, int j, char c)
{
  if (c == 'R')
    return j != w - 1;
  if (c == 'L')
    return j != 0;
  if (c == 'U')
    return i != 0;
  if (c == 'D')
    return i != h - 1;
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> h >> w;
  vector<string> g(h);
  rep(i, 0, h) cin >> g[i];
  int i = 0, j = 0;
  set<P> seen;
  while (true)
  {
    if (seen.count({i, j}) != 0)
    {
      cout << -1 << endl;
      return 0;
    }
    seen.insert({i, j});
    if (is_legal(i, j, g[i][j]))
      move(i, j, g[i][j]);
    else
    {
      cout << i + 1 << ' ' << j + 1 << endl;
      return 0;
    }
  }
}