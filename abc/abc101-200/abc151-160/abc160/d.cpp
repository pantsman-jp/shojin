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
  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;
  vector<vector<int>> g(n);
  g[x].push_back(y), g[y].push_back(x);
  rep(i, 0, n - 1) g[i].push_back(i + 1), g[i + 1].push_back(i);
  vector<int> ans(n);
  rep(i, 0, n) {
    queue<int> q;
    vector<int> dist(n, inf);
    dist[i] = 0;
    q.push(i);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : g[u]) {
        if (dist[v] != inf) continue;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
    rep(j, i + 1, n) ans[dist[j]]++;
  }
  rep(k, 1, n) cout << ans[k] << endl;
  return 0;
}