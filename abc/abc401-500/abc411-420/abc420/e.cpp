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
  vector<int> c(n), s(n);
  rep(_, 0, q) {
    int t, u, v;
    cin >> t;
    if (t == 1) {
      cin >> u >> v;
      u--, v--;
      u = uf.leader(u);
      v = uf.leader(v);
      if (u != v) {
        uf.merge(u, v);
        int w = uf.leader(u);
        s[w] = s[u] + s[v];
        s[u ^ v ^ w] = 0;
      }
    } else if (t == 2) {
      cin >> u;
      u--;
      s[uf.leader(u)] -= c[u];
      c[u] ^= 1;
      s[uf.leader(u)] += c[u];
    } else {
      cin >> u;
      u--;
      yn(s[uf.leader(u)] != 0);
    }
  }
  return 0;
}