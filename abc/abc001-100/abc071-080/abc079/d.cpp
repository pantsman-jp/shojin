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
  vector c(10, vector<int>(10));
  rep(i, 0, 10) rep(j, 0, 10) cin >> c[i][j];
  rep(k, 0, 10) rep(i, 0, 10) rep(j, 0, 10) chmin(c[i][j], c[i][k] + c[k][j]);
  vector a(h, vector<int>(w));
  ll ans = 0;
  rep(_, 0, h * w) {
    int a;
    cin >> a;
    if (a != -1) ans += c[a][1];
  }
  cout << ans << endl;
  return 0;
}