#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define YN(tf) cout << (tf ? "YES\n" : "NO\n")
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
template <typename T, typename U>
inline bool chmax(T& x, const U& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T, typename U>
inline bool chmin(T& x, const U& y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T>
inline T lcm(T a, T b) {
  return (a / std::gcd(a, b)) * b;
}
template <typename T>
inline T divceil(T a, T b) {
  return (a + b - 1) / b;
}
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using rpq = priority_queue<T, vector<T>, greater<T>>;
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

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  rep(i, 0, t) solve();
  return 0;
}

pii op_min(pii a, pii b) { return min(a, b); }

pii e_min() { return {inf, inf}; }

pii op_max(pii a, pii b) { return max(a, b); }

pii e_max() { return {-inf, -inf}; }

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  rep(i, 0, n) cin >> p[i];
  vector<pii> a(n);
  rep(i, 0, n) a[i] = {p[i], i};
  segtree<pii, op_min, e_min> seg_min(a);
  segtree<pii, op_max, e_max> seg_max(a);
  rep(_, 0, m) {
    int l, r;
    cin >> l >> r;
    l--;
    auto [foo, i] = seg_min.prod(l, r);
    auto [bar, j] = seg_max.prod(l, r);
    swap(p[i], p[j]);
    seg_min.set(i, {p[i], i});
    seg_min.set(j, {p[j], j});
    seg_max.set(i, {p[i], i});
    seg_max.set(j, {p[j], j});
  }
  rep(i, 0, n) cout << p[i] << ' ';
  cout << '\n';
}