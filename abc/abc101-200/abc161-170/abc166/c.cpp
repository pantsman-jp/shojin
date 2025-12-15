#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<ll> h;
vector<vector<int>> g;

bool dfs(int v)
{
  for (int u : g[v])
  {
    if (h[v] <= h[u])
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  h.resize(n), g.resize(n);
  rep(i, 0, n) cin >> h[i];
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  int ans = 0;
  rep(v, 0, n) if (dfs(v)) ans++;
  cout << ans << endl;
}