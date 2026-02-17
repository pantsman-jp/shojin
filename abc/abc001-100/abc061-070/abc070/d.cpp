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
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> g(n);
  rep(_, 0, n - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  int Q, k;
  cin >> Q >> k;
  queue<int> q;
  vector<ll> dist(n, INF);
  q.push(k - 1), dist[k - 1] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, c] : g[u]) {
      if (dist[v] < INF) continue;
      q.push(v);
      dist[v] = dist[u] + c;
    }
  }
  rep(_, 0, Q) {
    int x, y;
    cin >> x >> y;
    cout << dist[x - 1] + dist[y - 1] << endl;
  }
  return 0;
}