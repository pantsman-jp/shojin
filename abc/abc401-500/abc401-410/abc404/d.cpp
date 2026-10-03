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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> c(n);
  rep(i, 0, n) cin >> c[i];
  vector<vector<int>> a(m);
  rep(i, 0, m) {
    int k;
    cin >> k;
    a[i].resize(k);
    rep(j, 0, k) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  int pow3n = 1;
  rep(i, 0, n) pow3n *= 3;
  ll ans = INF;
  vector<int> x(n);
  rep(bit, 0, pow3n) {
    int t = bit;
    rep(i, 0, n) x[i] = t % 3, t /= 3;
    bool ok = true;
    rep(i, 0, m) {
      int cnt = 0;
      for (int j : a[i]) cnt += x[j];
      if (cnt < 2) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ll cost = 0;
      rep(i, 0, n) cost += c[i] * x[i];
      chmin(ans, cost);
    }
  }
  cout << ans << '\n';
}
