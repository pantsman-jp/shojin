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

int e() { return 0; }
int op(int x, int y) { return max(x, y); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> w(n), c(m);
  rep(i, 0, n) cin >> w[i];
  rep(i, 0, m) cin >> c[i];
  segtree<int, op, e> seg(c);
  int ans = 0;
  rep(i, 0, n) {
    auto f = [&](int x) { return x < w[i]; };
    int r = seg.max_right(0, f);
    if (r != m) {
      ans++;
      seg.set(r, 0);
    }
  }
  cout << ans << '\n';
  return 0;
}