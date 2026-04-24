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

int max_op(int x, int y) { return max(x, y); }

int min_op(int x, int y) { return min(x, y); }

int max_e() { return 0; }

int min_e() { return inf; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  segtree<int, max_op, max_e> mx(h);
  segtree<int, min_op, min_e> mn(h);
  ll ans = 0;
  rep(i, 0, n) {
    auto f = [&](int x) { return x <= h[i]; };
    int j = mx.max_right(i, f);
    if (j != n) ans += mn.prod(i, j);
  }
  cout << ans << '\n';
  return 0;
}