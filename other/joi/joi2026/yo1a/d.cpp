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
  int n;
  cin >> n;
  vector c(n, vector<char>(n));
  rep(i, 0, n) rep(j, 0, n) cin >> c[i][j];
  bool ok = false;
  rep(i, 0, n) {
    if (count(all(c[i]), 'o') == n or count(all(c[i]), 'x') == n) ok = true;
  }
  rep(j, 0, n) {
    vector<char> tmp;
    rep(i, 0, n) tmp.push_back(c[i][j]);
    if (count(all(tmp), 'o') == n or count(all(tmp), 'x') == n) ok = true;
  }
  yn(ok);
  return 0;
}