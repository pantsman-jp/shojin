#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

map<int, vector<int>> g;
vector<bool> b, cango;

void bfs(int v)
{
  queue<int> q;
  q.push(v);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int w : g[u])
    {
      if (!cango[w])
        cango[w] = true, q.push(w);
    }
  }
}

void solve()
{
  int t, v;
  cin >> t >> v;
  if (t == 1)
  {
    if (!b[v])
    {
      b[v] = true;
      if (!cango[v])
        cango[v] = true, bfs(v);
    }
  }
  else
  {
    if (cango[v])
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  b.resize(n + 1), cango.resize(n + 1);
  rep(_, 0, m)
  {
    int x, y;
    cin >> x >> y;
    g[y].push_back(x);
  }
  int q;
  cin >> q;
  rep(_, 0, q) solve();
}