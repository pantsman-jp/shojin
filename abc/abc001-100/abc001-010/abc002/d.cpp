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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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

int main() {
  int n, m;
  cin >> n >> m;
  vector adj(n, vector<bool>(n));
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u][v] = adj[v][u] = true;
  }
  int ans = 0;
  rep(bit, 0, 1 << n) {
    vector<int> group;
    rep(i, 0, n) if ((bit >> i) & 1 != 0) group.push_back(i);
    bool ok = true;
    rep(a, 0, group.size()) rep(b, a + 1, group.size()) {
      if (!adj[group[a]][group[b]]) ok = false;
    }
    if (ok) {
      int sz = group.size();
      if (ans < sz) ans = sz;
    }
  }
  cout << ans << '\n';
  return 0;
}