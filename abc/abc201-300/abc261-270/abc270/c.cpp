#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n, x, y;
vector<vector<int>> g;
vector<bool> seen;
deque<int> q;
bool stop;

void dfs(int k)
{
  if (!stop)
    q.push_back(k);
  if (k == y)
    stop = true;
  seen[k] = true;
  rep(i, 0, g[k].size()) if (!seen[g[k][i]]) dfs(g[k][i]);
  if (!stop)
    q.pop_back();
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> x >> y;
  g.resize(n + 1), seen.resize(n + 1);
  rep(_, 0, n - 1)
  {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v), g[v].push_back(u);
  }
  stop = false;
  dfs(x);
  while (!q.empty())
    cout << q.front() << ' ', q.pop_front();
  cout << endl;
}