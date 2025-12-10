#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

const vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};
const vector<int> dy = {2, 1, -1, -2, -2, -1, 1, 2};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  set<P> s1, s2;
  rep(i, 0, 8)
  {
    s1.insert(make_pair(x1 + dx[i], y1 + dy[i]));
    s2.insert(make_pair(x2 + dx[i], y2 + dy[i]));
  }
  vector<P> ans;
  set_intersection(all(s1), all(s2), back_inserter(ans));
  if (ans.empty())
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}