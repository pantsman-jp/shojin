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
  vector<vector<int>> g(n + 1);
  rep(_, 0, m)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  int ans = 0;
  rep(a, 1, n + 1) rep(b, a + 1, n + 1) rep(c, b + 1, n + 1)
  {
    if (find(all(g[a]), b) != g[a].end() and find(all(g[b]), c) != g[b].end() and find(all(g[c]), a) != g[c].end())
      ans++;
  }
  cout << ans << endl;
}