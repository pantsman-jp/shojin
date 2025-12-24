#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<vector<int>> g;

int dfs(int v)
{
  if (g[v].empty())
    return 1;
  vector<int> s;
  for (int u : g[v])
    s.push_back(dfs(u));
  sort(all(s));
  return s.front() + s.back() + 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  g.resize(n + 1);
  rep(i, 2, n + 1)
  {
    int b;
    cin >> b;
    g[b].push_back(i);
  }
  cout << dfs(1) << endl;
}