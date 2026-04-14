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
  int n, k, b;
  cin >> n >> k >> b;
  vector<ll> c(n), s(n);
  rep(i, 0, n) cin >> c[i] >> s[i];
  vector dp(k + 1, vector<ll>(b + 1, INF));
  dp[0][0] = 0;
  rep(idx, 0, n) rrep(i, 0, k) rep(j, 0, b + 1) {
    if (dp[i][j] == INF) continue;
    int nxt = j + c[idx];
    if (nxt <= b and s[idx] > dp[i][j]) chmin(dp[i + 1][nxt], s[idx]);
  }
  int ans = 0;
  rep(i, 0, k + 1) rep(j, 0, b + 1) {
    if (dp[i][j] < INF) chmax(ans, i);
  }
  cout << ans << '\n';
  return 0;
}