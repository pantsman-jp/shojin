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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> c(n), p(n);
  rep(i, 0, n) cin >> c[i] >> p[i];
  vector bad(n, vector<bool>(n));
  rep(_, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    bad[u][v] = true;
    bad[v][u] = true;
  }
  ll ans = 0;
  rep(bit, 0, 1 << n) {
    ll cost = 0, prof = 0;
    bool ok = true;
    rep(i, 0, n) {
      if ((bit & (1 << i)) != 0) {
        cost += c[i];
        prof += p[i];
        rep(j, 0, i) if ((bit & (1 << j)) != 0 and bad[i][j]) ok = false;
      }
    }
    if (!ok or cost > k) continue;
    chmax(ans, prof);
  }
  cout << ans << '\n';
  return 0;
}