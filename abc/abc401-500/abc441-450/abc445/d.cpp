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
  int h, w, n;
  cin >> h >> w >> n;
  vector<pii> piece;
  map<int, vector<int>> ys, xs;
  rep(i, 0, n) {
    int y, x;
    cin >> y >> x;
    piece.emplace_back(y, x);
    ys[y].push_back(i), xs[x].push_back(i);
  }
  vector<int> ansy(n), ansx(n);
  vector<bool> used(n, false);
  int y = 1, x = 1;
  int remy = h, remx = w;
  rep(_, 0, n) {
    while (!ys[remy].empty() and used[ys[remy].back()]) ys[remy].pop_back();
    if (!ys[remy].empty()) {
      int i = ys[remy].back();
      ys[remy].pop_back();
      used[i] = true;
      ansy[i] = y, ansx[i] = x;
      auto [_, dx] = piece[i];
      x += dx;
      remx -= dx;
    } else {
      while (!xs[remx].empty() and used[xs[remx].back()]) xs[remx].pop_back();
      int i = xs[remx].back();
      xs[remx].pop_back();
      used[i] = true;
      ansy[i] = y, ansx[i] = x;
      auto [dy, _] = piece[i];
      y += dy;
      remy -= dy;
    }
  }
  rep(i, 0, n) cout << ansy[i] << " " << ansx[i] << endl;
  return 0;
}