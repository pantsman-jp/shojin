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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int mix = 100 * a, sugar = 0;
  rep(i, 0, 31) rep(j, 0, 31) {
    int w = 100 * a * i + 100 * b * j;
    if (w > f) break;
    if (w == 0) continue;
    rep(k, 0, f + 1) {
      if (w + c * k > f) break;
      rep(l, 0, f + 1) {
        int s = c * k + d * l;
        if (w + s > f) break;
        if (s <= (w / 100) * e and 100 * sugar * (w + s) < 100 * s * mix) {
          mix = w + s;
          sugar = s;
        }
      }
    }
  }
  cout << mix << ' ' << sugar << '\n';
  return 0;
}