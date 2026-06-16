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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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
  int n, x, y;
  cin >> n >> x >> y;
  vector dp(x + 1, vector<int>(y + 1, inf));
  dp[0][0] = 0;
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    vector p(x + 1, vector<int>(y + 1, inf));
    swap(dp, p);
    rep(j, 0, x + 1) rep(k, 0, y + 1) {
      chmin(dp[j][k], p[j][k]);
      chmin(dp[min(j + a, x)][min(k + b, y)], p[j][k] + 1);
    }
  }
  cout << (dp[x][y] == inf ? -1 : dp[x][y]) << '\n';
  return 0;
}