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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector l(h, vector<int>(w)), r(h, vector<int>(w));
  vector u(h, vector<int>(w)), d(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) {
    if (s[i][j] == '.') l[i][j] = (j > 0 ? l[i][j - 1] : 0) + 1;
  }
  rep(i, 0, h) rrep(j, 0, w) {
    if (s[i][j] == '.') r[i][j] = (j < w - 1 ? r[i][j + 1] : 0) + 1;
  }
  rep(j, 0, w) rep(i, 0, h) {
    if (s[i][j] == '.') u[i][j] = (i ? u[i - 1][j] : 0) + 1;
  }
  rep(j, 0, w) rrep(i, 0, h) {
    if (s[i][j] == '.') d[i][j] = (i < h - 1 ? d[i + 1][j] : 0) + 1;
  }
  int ans = 0;
  rep(i, 0, h) rep(j, 0, w) {
    if (s[i][j] == '.') chmax(ans, l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3);
  }
  cout << ans << endl;
  return 0;
}