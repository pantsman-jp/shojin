#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define YN(tf) cout << (tf ? "YES\n" : "NO\n")
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
template <typename T, typename U>
inline bool chmax(T& x, const U& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T, typename U>
inline bool chmin(T& x, const U& y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T>
inline T lcm(T a, T b) {
  return (a / std::gcd(a, b)) * b;
}
template <typename T>
inline T divceil(T a, T b) {
  return (a + b - 1) / b;
}
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using rpq = priority_queue<T, vector<T>, greater<T>>;
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

void solve();

vector<ll> dijkstra(const vector<vector<pair<int, ll>>>& g, int s) {
  using pli = pair<ll, int>;
  rpq<pli> q;
  vector<ll> dist(g.size(), INF);
  dist[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : g[u]) {
      ll nd = d + w;
      if (nd < dist[v]) {
        dist[v] = nd;
        q.push({nd, v});
      }
    }
  }
  return dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  rep(i, 0, t) solve();
  return 0;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, ll>> edge(m);
  rep(i, 0, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edge[i] = {u - 1, v - 1, w};
  }
  int k;
  cin >> k;
  set<int> e;
  rep(i, 0, k) {
    int ei;
    cin >> ei;
    e.insert(ei - 1);
  }
  vector<vector<pair<int, ll>>> g1(n);
  for (auto [u, v, w] : edge) {
    g1[u].emplace_back(v, w);
    g1[v].emplace_back(u, w);
  }
  ll ans1 = dijkstra(g1, 0)[n - 1];
  cout << (ans1 == INF ? -1 : ans1) << '\n';
  vector<vector<pair<int, ll>>> g2(n);
  rep(i, 0, m) {
    if (e.find(i) != e.end()) continue;
    auto [u, v, w] = edge[i];
    g2[u].emplace_back(v, w);
    g2[v].emplace_back(u, w);
  }
  ll ans2 = dijkstra(g2, 0)[n - 1];
  cout << (ans2 == INF ? -1 : ans2) << '\n';
}
