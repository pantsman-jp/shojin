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
  int n, w;
  cin >> n >> w;
  vector<ll> l(n), c(n);
  rep(i, 0, n) cin >> l[i] >> c[i];
  vector<ll> dp(w + 1, INF);
  dp[0] = 0;
  rep(i, 0, n) {
    ll num = c[i];
    for (ll k = 1; num > 0; k <<= 1) {
      ll mul = min(k, num);
      ll length = l[i] * mul;
      ll count = mul;
      rrep(j, length, w + 1) {
        if (dp[j - length] != INF) chmin(dp[j], dp[j - length] + count);
      }
      num -= mul;
    }
  }
  if (dp[w] == INF)
    cout << -1 << '\n';
  else
    cout << dp[w] << '\n';
  return 0;
}