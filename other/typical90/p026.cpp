#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

vector<vector<int>> g;
vector<bool> seen;
vector<int> color;

void dfs(int u, int c)
{
  seen[u] = true;
  color[u] = c;
  for (int v : g[u])
    if (!seen[v])
      dfs(v, 3 - c);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  g.resize(n), seen.resize(n), color.resize(n);
  rep(_, 0, n - 1)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  dfs(0, 1);
  vector<int> x, y;
  rep(i, 0, n)
  {
    if (color[i] == 1)
      x.push_back(i + 1);
    else
      y.push_back(i + 1);
  }
  vector<int> ans;
  if (x.size() > y.size())
    ans = x;
  else
    ans = y;
  rep(i, 0, n / 2) cout << ans[i] << " ";
  cout << endl;
}