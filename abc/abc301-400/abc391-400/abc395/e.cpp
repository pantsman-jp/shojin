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
  int n, m;
  ll x;
  cin >> n >> m >> x;
  vector<vector<int>> g(2 * n);
  rep(i, 0, m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u * 2].push_back(v * 2);
    g[v * 2 + 1].push_back(u * 2 + 1);
  }
  priority_queue<pll, vector<pll>, greater<pll>> q;
  vector<ll> dist(2 * n, INF);
  auto push = [&](int v, ll d) {
    if (dist[v] <= d) return;
    dist[v] = d;
    q.emplace(d, v);
  };
  push(0, 0);
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (dist[u] != d) continue;
    for (int v : g[u]) push(v, d + 1);
    push(u ^ 1, d + x);
  }
  cout << min(dist[2 * (n - 1)], dist[2 * (n - 1) + 1]) << '\n';
}