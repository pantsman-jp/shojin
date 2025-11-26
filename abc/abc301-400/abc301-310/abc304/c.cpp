#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll d;
vector<ll> x, y;
vector<vector<int>> g;
vector<bool> ans;

bool is_near(int i, int j)
{
  return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]) <= d * d;
}

void dfs(int v)
{
  ans[v] = true;
  for (int u : g[v])
    if (!ans[u])
      dfs(u);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n >> d;
  x.resize(n + 1), y.resize(n + 1);
  rep(i, 1, n + 1) cin >> x[i] >> y[i];
  g.resize(n + 1);
  rep(i, 1, n + 1) rep(j, i + 1, n + 1) if (is_near(i, j)) g[i].push_back(j), g[j].push_back(i);
  ans.resize(n + 1);
  dfs(1);
  rep(i, 1, n + 1)
  {
    if (ans[i])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}