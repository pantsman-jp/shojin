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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  dsu uf(n);
  vector<vector<int>> top(n);
  rep(i, 0, n) top[i].push_back(i);
  rep(_, 0, q) {
    int t, u, v, k;
    cin >> t;
    if (t == 1) {
      cin >> u >> v;
      u--, v--;
      u = uf.leader(u);
      v = uf.leader(v);
      if (u == v) continue;
      vector<int> d = top[u];
      d.insert(d.end(), top[v].begin(), top[v].end());
      sort(rall(d));
      if (d.size() > 10) d.resize(10);
      uf.merge(u, v);
      top[uf.leader(u)] = d;
    } else {
      cin >> v >> k;
      v--;
      v = uf.leader(v);
      int ans = -1;
      if (top[v].size() >= k) ans = top[v][k - 1] + 1;
      cout << ans << '\n';
    }
  }
  return 0;
}