#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

map<int, vector<int>> g;
set<int> seen;

int dfs(int v)
{
  seen.insert(v);
  int ans = v;
  for (int u : g[v])
  {
    if (seen.count(u) != 0)
      continue;
    ans = max(ans, dfs(u));
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  rep(_, 0, n)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  cout << dfs(1) << endl;
}