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
  int n;
  cin >> n;
  vector<ll> x(1e5 + 1), a(1e5 + 1);
  rep(i, 0, n) {
    int t;
    cin >> t;
    cin >> x[t] >> a[t];
  }
  vector dp(5, vector<ll>(1e5 + 1, -INF));
  dp[0][0] = 0;
  rep(j, 0, 1e5) rep(i, 0, 5) {
    if (dp[i][j] == INF) continue;
    rep(ni, max(0, i - 1), min(4, i + 1) + 1) {
      ll val = dp[i][j];
      if (x[j + 1] == ni) val += a[j + 1];
      chmax(dp[ni][j + 1], val);
    }
  }
  ll ans = 0;
  rep(i, 0, 5) chmax(ans, dp[i][1e5]);
  cout << ans << endl;
  return 0;
}