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
  vector<int> a(m), pts(n);
  rep(i, 0, m) cin >> a[i];
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<vector<int>> unsolve_pts(n);
  rep(i, 0, n)
  {
    pts[i] = i + 1;
    rep(j, 0, m)
    {
      if (s[i][j] == 'o')
        pts[i] += a[j];
      else
        unsolve_pts[i].push_back(a[j]);
    }
    sort(all(unsolve_pts[i]), greater<int>());
  }
  rep(i, 0, n)
  {
    int max_other = 0;
    rep(j, 0, n) if (j != i) max_other = max(max_other, pts[j]);
    int need = max_other - pts[i] + 1, ans = 0;
    if (need <= 0)
      cout << ans << endl;
    else
    {
      int j = 0;
      while (need > 0 and j < unsolve_pts[i].size())
        need -= unsolve_pts[i][j], j++, ans++;
      cout << ans << endl;
    }
  }
}