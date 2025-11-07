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
    int a, b;
    cin >> a >> b;
    g[a].push_back(b), g[b].push_back(a);
  }
  rep(i, 1, n + 1) sort(all(g[i]));
  rep(i, 1, n + 1)
  {
    cout << g[i].size() << ' ';
    rep(j, 0, g[i].size()) cout << g[i][j] << ' ';
    cout << endl;
  }
}