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
  cin >> t;
  rep(i, 0, t) solve();
  return 0;
}

void solve() {
  int n;
  cin >> n;
  int m = 2 * n;
  vector<int> a(m);
  rep(i, 0, m) cin >> a[i];
  rep(i, 0, m) a[i]--;
  vector<vector<int>> is(n);
  rep(i, 0, m) is[a[i]].push_back(i);
  set<pii> cand;
  rep(i, 0, m - 1) {
    int x = a[i], y = a[i + 1];
    if (x > y) swap(x, y);
    if (x == y) continue;
    cand.emplace(x, y);
  }
  int ans = 0;
  for (auto [x, y] : cand) {
    int xl = is[x][0], xr = is[x][1];
    int yl = is[y][0], yr = is[y][1];
    if (xl + 1 == xr or yl + 1 == yr) continue;
    if (abs(xl - yl) == 1 and abs(xr - yr) == 1) ans++;
  }
  cout << ans << '\n';
}
