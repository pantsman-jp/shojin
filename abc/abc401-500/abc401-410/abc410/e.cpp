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
  int n, h, m;
  cin >> n >> h >> m;
  vector dp(n + 1, vector<int>(h + 1, -1));
  dp[0][h] = m;
  rep(i, 0, n) {
    int a, b;
    cin >> a >> b;
    rep(j, 0, h + 1) if (dp[i][j] != -1) {
      if (a <= j) chmax(dp[i + 1][j - a], dp[i][j]);
      if (b <= dp[i][j]) chmax(dp[i + 1][j], dp[i][j] - b);
    }
    if (dp[i + 1] == vector<int>(h + 1, -1)) {
      cout << i << endl;
      return 0;
    }
  }
  cout << n << endl;
  return 0;
}