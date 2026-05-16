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
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  vector a(n, vector<int>(m));
  rep(i, 0, n) rep(j, 0, m) a[i][j] = s[i][j] - '0';
  vector sum(n + 1, vector<int>(m + 1));
  rep(i, 0, n) rep(j, 0, m) {
    sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a[i][j];
  }
  int ans = -1;
  rep(h, 1, n + 1) {
    if (k % h != 0) continue;
    int w = k / h;
    if (w > m) continue;
    rep(r1, 0, n - h + 1) rep(c1, 0, m - w + 1) {
      int r2 = r1 + h;
      int c2 = c1 + w;
      chmax(ans, sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1]);
    }
  }
  cout << ans << '\n';
  return 0;
}