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
  vector a(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j], a[i][j] %= 2;
  vector<tuple<int, int, int, int>> ans;
  rep(i, 0, h) rep(j, 0, w) {
    if (a[i][j] == 0) continue;
    a[i][j] = 0;
    if (j != w - 1) {
      a[i][j + 1] = (a[i][j + 1] + 1) % 2;
      ans.emplace_back(i + 1, j + 1, i + 1, j + 2);
    } else if (i != h - 1) {
      a[i + 1][j] = (a[i + 1][j] + 1) % 2;
      ans.emplace_back(i + 1, j + 1, i + 2, j + 1);
    }
  }
  cout << ans.size() << endl;
  for (auto [a, b, c, d] : ans)
    cout << a << " " << b << " " << c << " " << d << endl;
  return 0;
}