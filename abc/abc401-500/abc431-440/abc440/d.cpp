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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  rep(_, 0, q) {
    int x, y;
    cin >> x >> y;
    int i = lower_bound(all(a), x) - a.begin();
    if (i == n) {
      cout << x + y - 1 << '\n';
      continue;
    }
    if (y <= a[i] - x) {
      cout << x + y - 1 << '\n';
      continue;
    }
    y -= a[i] - x;
    x = a[i] + 1;
    int l = i, r = n;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if ((a[mid] - a[i]) - (mid - i) >= y) {
        r = mid;
      } else {
        l = mid;
      }
    }
    y -= (a[l] - a[i]) - (l - i);
    x = a[l] + 1;
    cout << x + y - 1 << '\n';
  }
}