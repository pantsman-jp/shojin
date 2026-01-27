#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

bool is_bipartite(const vector<vector<int>> &g, vector<int> &label)
{
  int n = g.size();
  label.assign(n, -1);
  function<bool(int, int)> dfs = [&](int u, int l)
  {
    label[u] = l;
    for (int v : g[u])
    {
      if (label[v] == l)
        return false;
      if (label[v] == -1 and !dfs(v, l ^ 1))
        return false;
    }
    return true;
  };
  rep(i, 0, n) if (label[i] == -1 and !dfs(i, 0)) return false;
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  rep(i, 0, m) cin >> a[i], a[i]--;
  rep(i, 0, m) cin >> b[i], b[i]--;
  vector<vector<int>> g(n);
  rep(i, 0, m)
  {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  vector<int> label(n, -1);
  yn(is_bipartite(g, label));
}