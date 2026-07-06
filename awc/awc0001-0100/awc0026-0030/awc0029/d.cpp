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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> g(n);
  rep(_, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    if (w >= k) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }
  queue<int> q;
  q.push(0);
  vector<int> dist(n, inf);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] == inf) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  if (dist[n - 1] == inf)
    cout << -1 << '\n';
  else
    cout << dist[n - 1] << '\n';
  return 0;
}