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
  int t;
  cin >> t;
  rep(_, 0, t) {
    int n, c;
    cin >> n >> c;
    --c;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<int> down_wall(n, -1);
    rep(j, 0, n) rep(i, 0, n) if (s[i][j] == '#') chmax(down_wall[j], i);
    vector dp(n, vector<bool>(n));
    dp[n - 1][c] = true;
    rrep(i, 1, n) {
      rep(j, 0, n) {
        if (!dp[i][j]) continue;
        rep(dj, -1, 2) {
          int nj = j + dj;
          if (nj < 0 or nj >= n) continue;
          int ni = i - 1;
          if (s[ni][nj] == '.')
            dp[ni][nj] = true;
          else {
            if (down_wall[nj] <= ni) dp[ni][nj] = true;
          }
        }
      }
    }
    for (bool cond : dp[0]) cout << (cond ? '1' : '0');
    cout << endl;
  }
  return 0;
}