#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

deque<P> pos;

void solve()
{
  int t;
  cin >> t;
  if (t == 1)
  {
    char c;
    cin >> c;
    auto [x, y] = pos[0];
    if (c == 'R')
      pos.push_front({x + 1, y});
    if (c == 'L')
      pos.push_front({x - 1, y});
    if (c == 'U')
      pos.push_front({x, y + 1});
    if (c == 'D')
      pos.push_front({x, y - 1});
    pos.pop_back();
  }
  else
  {
    int p;
    cin >> p;
    p--;
    cout << pos[p].first << ' ' << pos[p].second << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  rep(i, 0, n) pos.push_back({i + 1, 0});
  rep(_, 0, q) solve();
}