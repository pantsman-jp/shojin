#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<vector<int>> g;
vector<bool> seen;

int dfs(int v)
{
  seen[v] = true;
  int ans = 1;
  for (int u : g[v])
    if (!seen[u])
      ans += dfs(u);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  rep(_, 0, m)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  int ans = 0;
  seen.resize(n + 1);
  rep(v, 1, n + 1) fill(all(seen), false), ans += dfs(v);
  cout << ans << endl;
}