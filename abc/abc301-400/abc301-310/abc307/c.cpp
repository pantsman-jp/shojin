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

struct Sheet {
  int h, w;
  vector<string> s;
  void input() {
    cin >> h >> w;
    s = vector<string>(h);
    rep(i, 0, h) cin >> s[i];
  }
  void clear() { rep(i, 0, h) rep(j, 0, w) s[i][j] = '.'; }
  bool copy(Sheet a, int di, int dj) {
    rep(i, 0, a.h) rep(j, 0, a.w) {
      if (a.s[i][j] == '.') continue;
      int ni = i + di, nj = j + dj;
      if (ni < 0 || ni >= h || nj < 0 || nj >= w) return false;
      s[ni][nj] = a.s[i][j];
    }
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  Sheet a, b, x;
  a.input();
  b.input();
  x.input();
  rep(ai, -a.h, x.h) rep(aj, -a.w, x.w) rep(bi, -b.h, x.h) rep(bj, -b.w, x.w) {
    Sheet y = x;
    y.clear();
    if (!y.copy(a, ai, aj) || !y.copy(b, bi, bj)) continue;
    if (x.s == y.s) {
      yn(true);
      return 0;
    }
  }
  yn(false);
  return 0;
}