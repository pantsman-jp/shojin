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

ll op(ll x, ll y) { return max(x, y); }

ll e() { return -INF; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, m;
  cin >> n >> k >> m;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> s(n + 1);
  rep(i, 0, n) s[i + 1] = s[i] + a[i];
  segtree<ll, op, e> seg0(n + 1), seg1(n + 1);
  seg0.set(0, 0);
  seg1.set(0, 0);
  rep(i, 1, n + 1) {
    seg0.set(i, seg1.prod(max(0, i - m + 1), i) - s[i]);
    seg1.set(i, seg0.prod(max(0, i - k + 1), i) + s[i]);
  }
  cout << max(seg0.get(n) + s[n], seg1.get(n)) << endl;
  return 0;
}