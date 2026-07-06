#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define dout(x) cout << fixed << setprecision(10) << x << "\n"
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
  vector<int> s(n);
  rep(i, 0, n) cin >> s[i];
  vector dp(n + 1, vector(2, vector<int>(2, -inf)));
  if (s[0] == 1) {
    dp[1][0][1] = 0;
  } else {
    dp[1][0][0] = 0;
    dp[1][0][1] = 1;
  }
  rep(i, 1, n) rep(pre2, 0, 2) rep(pre1, 0, 2) {
    if (dp[i][pre2][pre1] == -inf) continue;
    rep(now, 0, 2) {
      if (s[i] == 1 && now == 0) continue;
      if (pre2 == 1 && pre1 == 1 && now == 1) continue;
      int add = (s[i] == 0 && now == 1 ? 1 : 0);
      chmax(dp[i + 1][pre1][now], dp[i][pre2][pre1] + add);
    }
  }
  int ans = 0;
  rep(j, 0, 2) rep(k, 0, 2) chmax(ans, dp[n][j][k]);
  cout << ans << '\n';
  return 0;
}