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
#define yn(tf) cout << (tf ? "Yes\n" : "No\n");
#define dout(x) cout << fixed << setprecision(10) << x << "\n";
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
  int n, sum = 0;
  cin >> n;
  vector<int> t(n);
  rep(i, 0, n) cin >> t[i], sum += t[i];
  vector dp(n + 1, vector<bool>(sum + 1));
  dp[0][0] = true;
  rep(i, 0, n) rep(j, 0, sum + 1) {
    dp[i + 1][j] = dp[i][j];
    if (j >= t[i]) dp[i + 1][j] = dp[i + 1][j] or dp[i][j - t[i]];
  }
  int ans = inf;
  rep(j, 0, sum + 1) if (dp[n][j]) chmin(ans, max(j, sum - j));
  cout << ans << endl;
  return 0;
}