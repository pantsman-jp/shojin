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

struct S {
  ll sum;
  ll size;
};

struct F {
  ll add;
};

S op(S a, S b) { return S{a.sum + b.sum, a.size + b.size}; }

S e() { return S{0, 0}; }

S mapping(F f, S x) { return S{x.sum + f.add * x.size, x.size}; }

F composition(F f, F g) { return F{f.add + g.add}; }

F id() { return F{0}; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<S> init(n);
  rep(i, 0, n) {
    ll c;
    cin >> c;
    init[i] = S{c, 1};
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(init);
  rep(_, 0, q) {
    int t, l, r;
    cin >> t >> l >> r;
    l--;
    if (t == 1) {
      ll v;
      cin >> v;
      seg.apply(l, r, F{v});
    } else {
      cout << seg.prod(l, r).sum << '\n';
    }
  }
  return 0;
}