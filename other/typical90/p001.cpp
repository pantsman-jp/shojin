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
  return (a / gcd(a, b)) * b;
}
template <typename T>
inline T ceil(T a, T b) {
  return (a + b - 1) / b;
}
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, L, K;
  cin >> N >> L >> K;
  vector<int> a(N);
  rep(i, 0, N) cin >> a[i];
  auto check = [&](int x) -> bool {
    int cnt = 0, prev = 0;
    rep(i, 0, N) {
      if (a[i] - prev >= x) {
        cnt++;
        prev = a[i];
      }
    }
    if (L - prev >= x) ++cnt;
    return cnt >= K + 1;
  };
  int l = 1, r = L + 1;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    if (check(mid))
      l = mid + 1;
    else
      r = mid - 1;
  }
  cout << r << '\n';
  return 0;
}