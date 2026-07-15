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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  rep(i, 0, t) solve();
  return 0;
}

vector<vector<ll>> warshall_floyd(const vector<vector<pair<int, ll>>>& g) {
  int n = g.size();
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  rep(i, 0, n) dist[i][i] = 0;
  rep(i, 0, n) for (const auto& e : g[i]) chmin(dist[i][e.first], e.second);
  rep(k, 0, n) rep(i, 0, n) {
    if (dist[i][k] < INF) {
      rep(j, 0, n) {
        if (dist[k][j] < INF) chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, ll>>> g(n);
  rep(_, 0, m) {
    int u, v;
    ll l;
    cin >> u >> v >> l;
    u--, v--;
    g[u].push_back({v, l});
    g[v].push_back({u, l});
  }
  vector<vector<pair<int, ll>>> h(n);
  rep(u, 1, n) {
    for (auto [v, l] : g[u]) {
      if (v == 0) continue;
      h[u].push_back({v, l});
    }
  }
  auto dist = warshall_floyd(h);
  ll ans = INF;
  for (auto [u, c1] : g[0]) {
    for (auto [v, c2] : g[0]) {
      if (u == v or dist[u][v] == INF) continue;
      chmin(ans, c1 + dist[u][v] + c2);
    }
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}