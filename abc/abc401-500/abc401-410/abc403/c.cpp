#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int n, m;
vector<bool> all;
vector<unordered_set<int>> grant;

void solve()
{
  int t, x, y;
  cin >> t >> x;
  x--;
  if (t == 1)
  {
    cin >> y;
    y--;
    grant[x].insert(y);
  }
  if (t == 2)
    all[x] = true;
  if (t == 3)
  {
    cin >> y;
    y--;
    if (all[x] or (grant[x].count(y) != 0))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> n >> m >> q;
  all.assign(n, false), grant.resize(n);
  rep(qi, 0, q) solve();
}