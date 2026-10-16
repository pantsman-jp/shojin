// Template: https://github.com/pantsman-jp/shojin/blob/main/abc/template/e.cpp
// License: CC0 1.0 Universal
// https://github.com/pantsman-jp/shojin/blob/main/LICENSE
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

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  vector<pii> edge;
  rep(i, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    edge.emplace_back(a, b);
  }
  vector<int> t(n);
  auto dfs = [&](auto dfs, int v, int p = -1) -> int {
    t[v] = 1;
    for (int u : g[v]) {
      if (u != p) {
        t[v] += dfs(dfs, u, v);
      }
    }
    return t[v];
  };
  dfs(dfs, 0);
  vector<ll> d(n);
  rep(i, 0, n - 1) {
    auto [a, b] = edge[i];
    if (t[a] < t[b]) swap(a, b);
    if (t[b] > n - t[b]) {
      d[b] += i + 1;
    } else {
      d[0] += i + 1;
      d[b] -= i + 1;
    }
  }
  auto dfs2 = [&](auto dfs2, int v, int p = -1) -> void {
    for (int u : g[v]) {
      if (u != p) {
        d[u] += d[v];
        dfs2(dfs2, u, v);
      }
    }
  };
  dfs2(dfs2, 0);
  rep(i, 0, n) cout << d[i] << ' ';
  cout << '\n';
}
