#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
  int m;
  cin >> m;
  vector<vector<bool>> bad(n, vector<bool>(n));
  rep(i, 0, m)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    bad[x][y] = true, bad[y][x] = true;
  }
  vector<int> p(n);
  iota(all(p), 0);
  int ans = 1 << 30;
  do
  {
    bool ok = true;
    rep(i, 0, n - 1) if (bad[p[i]][p[i + 1]]) ok = false;
    if (!ok)
      continue;
    int sum = 0;
    rep(i, 0, n) sum += a[p[i]][i];
    ans = min(ans, sum);
  } while (next_permutation(all(p)));
  if (ans == (1 << 30))
    ans = -1;
  cout << ans << endl;
}
