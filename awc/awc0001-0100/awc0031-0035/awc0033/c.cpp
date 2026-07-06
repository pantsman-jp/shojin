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
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  int ans = 0;
  vector<int> level(n);
  queue<int> q;
  rep(i, 0, k) {
    int c;
    cin >> c;
    c--;
    level[c] = t;
    q.push(c);
    ans++;
  }
  vector<vector<int>> g(n);
  rep(_, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      level[v]++;
      if (level[v] == t) {
        q.push(v);
        ans++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}