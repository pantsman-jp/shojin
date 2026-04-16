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
  int n, s, t;
  cin >> n >> s >> t;
  vector<ll> p(n), c(n), w(n), v(n);
  rep(i, 0, n) {
    cin >> p[i] >> c[i] >> w[i];
    v[i] = p[i] - c[i];
  }
  vector dp(n + 1, vector<ll>(s + 1, -INF));
  dp[0][0] = 0;
  rep(i, 0, n) rrep(k, 0, i + 1) rep(j, 0, s + 1) {
    if (dp[k][j] == -INF) continue;
    if (j + w[i] <= s) chmax(dp[k + 1][j + w[i]], dp[k][j] + v[i]);
  }
  int ans = -1;
  rep(k, 0, n + 1) rep(j, 0, s + 1) {
    if (dp[k][j] >= t) {
      ans = k;
      break;
    }
    if (ans != -1) break;
  }
  cout << ans << '\n';
  return 0;
}