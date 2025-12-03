#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

map<int, set<int>> f;

void solve()
{
  int t, a, b;
  cin >> t >> a >> b;
  if (t == 1)
    f[b].insert(a);
  else if (t == 2)
    f[b].erase(a);
  else
  {
    if (f[a].find(b) != f[a].end() and f[b].find(a) != f[b].end())
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  rep(_, 0, q) solve();
}