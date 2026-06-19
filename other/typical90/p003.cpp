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
inline T ceil(T a, T b) {
  return (a + b - 1) / b;
}
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
  vector<vector<int>> g(n);
  rep(_, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  queue<int> q;
  vector<int> dist(n, inf);
  q.push(0), dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u])
      if (dist[v] == inf) dist[v] = dist[u] + 1, q.push(v);
  }
  int mx = 0, vertex = 0;
  rep(i, 0, n) if (mx < dist[i]) mx = dist[i], vertex = i;
  queue<int> q2;
  vector<int> dist2(n, inf);
  q2.push(vertex), dist2[vertex] = 0;
  while (!q2.empty()) {
    int u = q2.front();
    q2.pop();
    for (int v : g[u])
      if (dist2[v] == inf) dist2[v] = dist2[u] + 1, q2.push(v);
  }
  cout << *max_element(all(dist2)) + 1 << '\n';
  return 0;
}