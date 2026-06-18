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
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector dp(n + 1, vector<int>(m + 1));
  rep(i, 0, n) rep(j, 0, m) {
    if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
    chmax(dp[i + 1][j + 1], dp[i + 1][j]);
    chmax(dp[i + 1][j + 1], dp[i][j + 1]);
  }
  string ans = "";
  while (n > 0 and m > 0) {
    if (dp[n][m] == dp[n - 1][m])
      n--;
    else if (dp[n][m] == dp[n][m - 1])
      m--;
    else {
      ans = s[n - 1] + ans;
      n--, m--;
    }
  }
  cout << ans << endl;
  return 0;
}