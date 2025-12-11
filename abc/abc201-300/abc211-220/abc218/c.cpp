#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n;

set<P> rotate90(const set<P> &s)
{
  set<P> ans;
  for (auto [x, y] : s)
    ans.insert({y, -x});
  return ans;
}

set<P> normalize(const set<P> &s)
{
  if (s.empty())
    return {};
  int min_x = 200, min_y = 200;
  for (auto [x, y] : s)
    min_x = min(min_x, x), min_y = min(min_y, y);
  set<P> ans;
  for (auto [x, y] : s)
    ans.insert({x - min_x, y - min_y});
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  vector<string> s(n), t(n);
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, n) cin >> t[i];
  set<P> ps, pt;
  rep(i, 0, n) rep(j, 0, n)
  {
    if (s[i][j] == '#')
      ps.insert({i, j});
    if (t[i][j] == '#')
      pt.insert({i, j});
  }
  if (ps.size() != pt.size())
  {
    cout << "No" << endl;
    return 0;
  }
  ps = normalize(ps), pt = normalize(pt);
  rep(rot, 0, 4)
  {
    if (ps == pt)
    {
      cout << "Yes" << endl;
      return 0;
    }
    ps = normalize(rotate90(ps));
  }
  cout << "No" << endl;
}