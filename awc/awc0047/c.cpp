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

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n + 2);
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<ll> ini(n + 2);
  segtree<ll, op, e> st(ini);
  rep(_, 0, q) {
    int t, p;
    ll l, r, x;
    cin >> t;
    if (t == 1) {
      cin >> l >> r >> x;
      st.set(l, st.get(l) + x);
      st.set(r + 1, st.get(r + 1) - x);
    } else {
      cin >> p;
      cout << a[p] + st.prod(0, p + 1) << '\n';
    }
  }
  return 0;
}