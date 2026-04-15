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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> c(n);
  rep(i, 0, n) {
    int k;
    cin >> k;
    c[i].resize(k);
    rep(j, 0, k) cin >> c[i][j], c[i][j]--;
  }
  vector<int> match(m, -1);
  vector<bool> seen(m);
  auto dfs = [&](auto dfs, int u) -> bool {
    for (int v : c[u]) {
      if (seen[v]) continue;
      seen[v] = true;
      if (match[v] == -1 or dfs(dfs, match[v])) {
        match[v] = u;
        return true;
      }
    }
    return false;
  };
  int ans = 0;
  rep(i, 0, n) {
    seen.assign(m, false);
    if (dfs(dfs, i)) ans++;
  }
  cout << ans << '\n';
  return 0;
}