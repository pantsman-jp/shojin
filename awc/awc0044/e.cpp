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
using mint = modint998244353;
// using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> d(n);
  rep(i, 0, n) cin >> d[i];
  ll lim = min(n, m);
  vector<mint> dp(lim + 1);
  dp[0] = 1;
  rep(i, 0, n) {
    vector<mint> next_dp(lim + 1);
    rep(j, 0, lim + 1) {
      if (dp[j] == 0) continue;
      if (d[i] == 0) {
        if (j > 0) next_dp[j] += dp[j] * j;
        if (j < lim) next_dp[j + 1] += dp[j] * (m - j);
      } else {
        if (d[i] <= j)
          next_dp[j] += dp[j];
        else if (d[i] == j + 1 && j < lim)
          next_dp[j + 1] += dp[j] * (m - j);
      }
    }
    dp = move(next_dp);
  }
  mint ans = 0;
  rep(j, 0, lim + 1) ans += dp[j];
  cout << ans.val() << '\n';
  return 0;
}