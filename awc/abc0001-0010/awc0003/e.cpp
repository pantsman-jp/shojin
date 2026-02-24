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
  int n, m;
  cin >> n >> m;
  vector<ll> w(n), c(m);
  rep(i, 0, n) cin >> w[i];
  rep(i, 0, m) cin >> c[i];
  int full = 1 << n;
  vector<ll> sum(full);
  rep(mask, 0, full) rep(i, 0, n) if ((mask >> i & 1) != 0) sum[mask] += w[i];
  vector<int> dp(full);
  dp[0] = 1;
  rep(j, 0, m) {
    vector<int> next = dp;
    rep(mask, 0, full) {
      if (!dp[mask]) continue;
      int remain = ((full - 1) ^ mask);
      for (int sub = remain; sub; sub = (sub - 1) & remain)
        if (sum[sub] <= c[j]) next[mask | sub] = 1;
    }
    dp = next;
  }
  yn(dp[full - 1] != 0);
  return 0;
}