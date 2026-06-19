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

vector<vector<int>> calc_next(const string& s) {
  int n = (int)s.size();
  vector<vector<int>> ans(n + 1, vector<int>(26, n));
  rrep(i, 0, n) {
    ans[i] = ans[i + 1];
    ans[i][s[i] - 'a'] = i;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  string s;
  cin >> n >> k >> s;
  auto nex = calc_next(s);
  string ans = "";
  int j = -1;
  rep(i, 0, k) rep(c, 0, 26) {
    int idx = nex[j + 1][c];
    if (n - idx >= k - i) {
      ans += char('a' + c);
      j = idx;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}