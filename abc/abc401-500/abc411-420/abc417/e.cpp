#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define dout(x) cout << fixed << setprecision(10) << x << "\n"
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

vector<vector<int>> g;
vector<bool> seen;

vector<int> dfs(int x, int y, vector<int> ans) {
  seen[x] = true;
  ans.push_back(x);
  if (x == y) return ans;
  for (int u : g[x]) {
    if (seen[u]) continue;
    vector<int> tmp = dfs(u, y, ans);
    if (!tmp.empty() and tmp.back() == y) return tmp;
  }
  return {};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    x--, y--;
    g.assign(n, {});
    seen.assign(n, false);
    rep(_, 0, m) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    rep(i, 0, n) sort(all(g[i]));
    for (int u : dfs(x, y, {})) cout << u + 1 << endl;
    cout << endl;
  }
  return 0;
}