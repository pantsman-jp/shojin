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
  vector<vector<int>> s(m);
  rep(i, 0, m)
  {
    int k;
    cin >> k;
    rep(j, 0, k)
    {
      int a;
      cin >> a;
      a--;
      s[i].push_back(a);
    }
  }
  vector<int> p(m);
  rep(i, 0, m) cin >> p[i];
  ll ans = 0;
  rep(bit, 0, 1 << n)
  {
    bool ok = true;
    for (int i = 0; i < m; ++i)
    {
      int on = 0;
      for (auto v : s[i])
      {
        if (bit & (1 << v))
          on++;
      }
      if (on % 2 != p[i])
        ok = false;
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
}