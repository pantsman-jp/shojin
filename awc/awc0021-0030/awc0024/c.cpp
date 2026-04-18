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
  vector<string> g(h);
  rep(i, 0, h) cin >> g[i];
  vector row(h, vector<int>(26)), col(w, vector<int>(26));
  rep(i, 0, h) rep(j, 0, w) row[i][g[i][j] - 'a']++, col[j][g[i][j] - 'a']++;
  string ans = "";
  rep(i, 0, h) rep(j, 0, w) {
    if (row[i][g[i][j] - 'a'] == 1 and col[j][g[i][j] - 'a'] == 1)
      ans += g[i][j];
  }
  cout << ans << '\n';
  return 0;
}