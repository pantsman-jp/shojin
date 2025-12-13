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
  int n, m;
  cin >> n >> m;
  set<P> placed;
  int ans = 0;
  rep(_, 0, m)
  {
    int r, c;
    cin >> r >> c;
    set<P> s = {
        {r, c},
        {r + 1, c},
        {r, c + 1},
        {r + 1, c + 1}};
    bool ok = true;
    for (auto p : s)
      if (placed.count(p) != 0)
        ok = false;
    if (ok)
    {
      ans++;
      for (auto p : s)
        placed.insert(p);
    }
  }
  cout << ans << endl;
}