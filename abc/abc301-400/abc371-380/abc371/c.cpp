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
  int n, mg, mh;
  cin >> n >> mg;
  vector<vector<int>> g(n, vector<int>(n, 0)), h(n, vector<int>(n, 0));
  rep(i, 0, mg)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u][v] = g[v][u] = 1;
  }
  cin >> mh;
  rep(i, 0, mh)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    h[a][b] = h[b][a] = 1;
  }
  vector<vector<int>> a(n, vector<int>(n, 0));
  rep(i, 0, n) rep(j, i + 1, n)
  {
    cin >> a[i][j];
    a[j][i] = a[i][j];
  }
  vector<int> p(n);
  rep(i, 0, n) p[i] = i;
  ll ans = inf, sum = 0;
  rep(i, 0, n) rep(j, i + 1, n) if (g[p[i]][p[j]] != h[i][j]) sum += a[i][j];
  ans = min(ans, sum);
  while (next_permutation(all(p)))
  {
    ll sum = 0;
    rep(i, 0, n) rep(j, i + 1, n) if (g[p[i]][p[j]] != h[i][j]) sum += a[i][j];
    ans = min(ans, sum);
  }
  cout << ans << endl;
}