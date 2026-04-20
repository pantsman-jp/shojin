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
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> b(n), w(k);
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, k) cin >> w[i];
  vector<tuple<int, int, int>> e(m);
  rep(i, 0, m) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    e[i] = {u, v, c};
  }
  ll required = 0;
  rep(i, 0, n) required += b[i];
  int q;
  cin >> q;
  vector<bool> ok(k, true);
  rep(_, 0, q) {
    int s;
    cin >> s;
    s--;
    ok[s] = false;
    mf_graph<ll> g(n + k + 2);
    for (auto [u, v, c] : e) {
      g.add_edge(u, v, c);
      g.add_edge(v, u, c);
    }
    rep(i, 0, n) g.add_edge(n + k, i, b[i]);
    rep(i, 0, k) if (ok[i]) g.add_edge(n + i, n + k + 1, w[i]);
    yn(g.flow(n + k, n + k + 1) == required);
  }
  return 0;
}