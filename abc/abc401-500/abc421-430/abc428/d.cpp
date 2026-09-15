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

ll sqrt_floor(const ll& x) {
  ll ans = sqrt((ld)x);
  while ((ans + 1) <= x / (ans + 1)) ans++;
  while (ans > x / ans) ans--;
  return ans;
}

ll cnt_sqr(ll l, ll r) { return sqrt_floor(r) - sqrt_floor(l - 1); }

ll f(ll x, ll y) {
  ll ans = 0;
  for (ll p = 1;; p *= 10) {
    ll base = x * p * 10;
    ll nl = base + p;
    ll nr = min(base + p * 10 - 1, base + y);
    if (nr < nl) return ans;
    ans += cnt_sqr(nl, nr);
  }
}

void solve() {
  ll c, d;
  cin >> c >> d;
  cout << f(c, c + d) - f(c, c) << '\n';
}