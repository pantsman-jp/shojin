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
// const ll mod = 998244353;
// const ll mod = 1e9 + 7;

int n, m, l, s, t;
vector<vector<P>> g;
vector<bool> ok;

void dfs(int u, int depth, int cost)
{
  if (cost > t)
    return;
  if (depth == l)
  {
    if (s <= cost and cost <= t)
      ok[u] = true;
    return;
  }
  for (auto [v, c] : g[u])
    dfs(v, depth + 1, cost + c);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> l >> s >> t;
  g.resize(n);
  rep(_, 0, m)
  {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    g[u].push_back({v, c});
  }
  ok.resize(n);
  dfs(0, 0, 0);
  rep(i, 0, n) if (ok[i]) cout << i + 1 << ' ';
  cout << endl;
}