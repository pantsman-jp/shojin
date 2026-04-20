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
  fenwick_tree<ll> seg(n + 1);
  rep(i, 1, n + 1) {
    int s;
    cin >> s;
    seg.add(i, s);
  }
  vector<ll> memo(500);
  rep(_, 0, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, v;
      cin >> k >> v;
      if (k < 500)
        memo[k] += v;
      else
        for (int i = k; i <= n; i += k) seg.add(i, v);
    } else {
      int x;
      cin >> x;
      ll ans = seg.sum(0, x + 1);
      rep(i, 1, 500) ans += (x / i) * memo[i];
      cout << ans << endl;
    }
  }
  return 0;
}