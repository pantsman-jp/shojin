#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<vector<int>> g;
vector<bool> seen;

void dfs(int v)
{
  seen[v] = true;
  for (int u : g[v])
  {
    if (!seen[u])
      dfs(u);
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  g.resize(n);
  rep(i, 0, m)
  {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    g[a[i]].push_back(b[i]), g[b[i]].push_back(a[i]);
  }
  int ans = 0;
  rep(i, 0, m)
  {
    auto it1 = find(all(g[a[i]]), b[i]);
    auto it2 = find(all(g[b[i]]), a[i]);
    int x = *it1, y = *it2;
    g[a[i]].erase(it1), g[b[i]].erase(it2);
    seen.assign(n, false);
    dfs(0);
    bool connect = true;
    rep(j, 0, n) if (!seen[j]) connect = false;
    if (!connect)
      ans++;
    g[a[i]].push_back(x), g[b[i]].push_back(y);
  }
  cout << ans << endl;
}