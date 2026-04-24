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

ll gap(ll x, ll y) { return max(x, y) - min(x, y); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> p(n), w(n - 1);
  rep(i, 0, n) cin >> p[i];
  rep(i, 0, n - 1) cin >> w[i];
  vector dp(1 << n, vector<ll>(n, -INF));
  rep(i, 0, n) dp[1 << i][i] = 0;
  rep(i, 0, 1 << n) rep(j, 0, n) {
    if (dp[i][j] < 0) continue;
    rep(k, 0, n) {
      if (i & (1 << k)) continue;
      int pc = __builtin_popcount(i) - 1;
      chmax(dp[i | (1 << k)][k], dp[i][j] + gap(p[j], p[k]) * w[pc]);
    }
  }
  cout << *max_element(all(dp[(1 << n) - 1])) << '\n';
  return 0;
}