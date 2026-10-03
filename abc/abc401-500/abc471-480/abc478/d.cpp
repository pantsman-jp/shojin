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

int op(int a, int b) { return a + b; }

int e() { return 0; }

int mapping(int f, int x) { return f + x; }

int composition(int f, int g) { return f + g; }

int id() { return 0; }

void solve() {
  int n, q;
  cin >> n >> q;
  vector<vector<pair<int, int>>> v(q + 1);
  rep(_, 0, q) {
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--;
    v[x].emplace_back(l, r);
  }
  lazy_segtree<int, op, e, int, mapping, composition, id> seg(n);
  rep(x, 1, q + 1) {
    auto p = v[x];
    sort(all(p));
    int l = -1, r = -1;
    for (auto [nl, nr] : p) {
      if (l == -1) {
        l = nl;
        r = nr;
      } else if (nl <= r + 1) {
        chmax(r, nr);
      } else {
        seg.apply(l, r + 1, 1);
        l = nl;
        r = nr;
      }
    }
    if (l != -1) seg.apply(l, r + 1, 1);
  }
  rep(i, 0, n) cout << seg.get(i) << ' ';
  cout << '\n';
}
