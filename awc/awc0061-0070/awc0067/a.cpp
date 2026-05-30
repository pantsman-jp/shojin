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
  int n, q;
  cin >> n >> q;
  vector<ll> pts(n);
  rep(_, 0, q) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      ll v;
      cin >> a >> b >> v;
      pts[a - 1] -= v, pts[b - 1] += v;
    } else if (t == 2) {
      int x, l, r;
      cin >> x >> l >> r;
      ll p = pts[x - 1];
      int ans = 0;
      rep(i, l - 1, r) if (pts[i] > p) ans++;
      cout << ans << '\n';
    } else {
      int l, r;
      ll v;
      cin >> l >> r >> v;
      rep(i, l - 1, r) pts[i] += v;
    }
  }
  return 0;
}