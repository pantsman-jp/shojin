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
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

ll c2(ll n) { return n * (n - 1) / 2; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(_, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector<int> label(n, -1);
  ll b, w;
  auto dfs = [&](auto dfs, int u, int l) -> bool {
    if (label[u] != -1) return label[u] == l;
    label[u] = l;
    if (l == 0)
      b++;
    else
      w++;
    for (int v : g[u])
      if (!dfs(dfs, v, (l + 1) % 2)) return false;
    return true;
  };
  ll ans = c2(n) - m;
  rep(i, 0, n) {
    if (label[i] != -1) continue;
    b = 0, w = 0;
    if (!dfs(dfs, i, 0)) {
      cout << 0 << endl;
      return 0;
    }
    ans -= c2(b) + c2(w);
  }
  cout << ans << endl;
  return 0;
}