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
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, d;
  cin >> n >> k >> d;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector dp(n + 1, vector(k + 1, vector<ll>(d, -1)));
  dp[0][0][0] = 0;
  rep(i, 0, n) rep(j, 0, k + 1) rep(r, 0, d) {
    ll now = dp[i][j][r];
    if (now == -1) continue;
    chmax(dp[i + 1][j][r], now);
    if (j < k) chmax(dp[i + 1][j + 1][(r + a[i]) % d], now + a[i]);
  }
  cout << dp[n][k][0] << endl;
  return 0;
}