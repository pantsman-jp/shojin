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
#define yn(tf) cout << (tf ? "Yes\n" : "No\n");
#define dout(x) cout << fixed << setprecision(10) << x << "\n";
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
  vector<pii> pos(n);
  rep(i, 0, n) cin >> pos[i].first >> pos[i].second;
  map<pii, int> id;
  rep(i, 0, n) id[pos[i]] = i;
  dsu uf(n);
  rep(i, 0, n) {
    auto [x, y] = pos[i];
    const vector<int> dx = {1, 0, 1};
    const vector<int> dy = {0, 1, 1};
    rep(j, 0, 3) {
      int nx = x + dx[j], ny = y + dy[j];
      if (id.count({nx, ny}) != 0) uf.merge(i, id[{nx, ny}]);
    }
  }
  int ans = 0;
  rep(i, 0, n) if (uf.leader(i) == i) ans++;
  cout << ans << endl;
  return 0;
}