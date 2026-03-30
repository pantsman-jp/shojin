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
  dsu uf(h * w);
  rep(i, 0, h) rep(j, 0, w - 1) if (s[i][j] == '.' and s[i][j + 1] == '.') {
    uf.merge(i * w + j, i * w + (j + 1));
  }
  rep(i, 0, h - 1) rep(j, 0, w) if (s[i][j] == '.' and s[i + 1][j] == '.') {
    uf.merge(i * w + j, (i + 1) * w + j);
  }
  set<int> all, out;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '.') {
    all.insert(uf.leader(i * w + j));
    if (i == 0 or i == h - 1 or j == 0 or j == w - 1)
      out.insert(uf.leader(i * w + j));
  }
  cout << all.size() - out.size() << '\n';
  return 0;
}