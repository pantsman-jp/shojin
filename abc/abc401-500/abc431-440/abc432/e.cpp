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
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  fenwick_tree<ll> tc(505050), ts(505050);
  rep(i, 0, n) tc.add(a[i], 1), ts.add(a[i], a[i]);
  rep(_, 0, q) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      x--;
      tc.add(a[x], -1);
      ts.add(a[x], -a[x]);
      a[x] = y;
      tc.add(a[x], 1);
      ts.add(a[x], a[x]);
    } else {
      ll ans = 0;
      if (x > y) {
        ans = (ll)n * x;
      } else {
        ans += tc.sum(0, x) * x;
        ans += ts.sum(x, y);
        ans += tc.sum(y, 505050) * y;
      }
      cout << ans << endl;
    }
  }
  return 0;
}