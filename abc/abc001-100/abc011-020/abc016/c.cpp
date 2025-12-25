#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<vector<int>> g;

void solve(int v)
{
  set<int> cnt;
  for (int u : g[v])
  {
    for (int x : g[u])
      cnt.insert(x);
  }
  cnt.erase(v);
  for (int u : g[v])
    cnt.erase(u);
  cout << cnt.size() << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  rep(_, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  rep(i, 0, n) solve(i);
}