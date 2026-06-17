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
inline T ceil(T a, T b) {
  return (a + (b - 1)) / b;
}
template <typename T>
inline T floor(T a, T b) {
  return a / b;
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
  int n;
  cin >> n;
  vector<pii> event;
  rep(_, 0, n) {
    int a, b;
    cin >> a >> b;
    event.emplace_back(a, 1);
    event.emplace_back(a + b, -1);
  }
  sort(all(event));
  vector<int> ans(n + 1);
  int cnt = 0, prev = 0;
  rep(i, 0, 2 * n - 1) {
    cnt += event[i].second;
    ans[cnt] += event[i + 1].first - event[i].first;
  }
  rep(i, 1, n + 1) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}