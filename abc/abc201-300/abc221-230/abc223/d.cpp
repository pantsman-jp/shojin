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
  return (a / gcd(a, b)) * b;
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

vector<int> topo_sort(vector<vector<int>>& g) {
  int n = g.size();
  vector<int> indeg(n, 0);
  rep(u, 0, n) for (int v : g[u]) indeg[v]++;
  priority_queue<int, vector<int>, greater<int>> q;
  rep(u, 0, n) if (indeg[u] == 0) q.push(u);
  vector<int> ans;
  while (!q.empty()) {
    int u = q.top();
    q.pop();
    ans.push_back(u);
    for (int v : g[u]) {
      indeg[v]--;
      if (indeg[v] == 0) q.push(v);
    }
  }
  if (ans.size() != n) return {};
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  rep(_, 0, m) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
  }
  vector<int> ans = topo_sort(g);
  if (ans.empty()) {
    cout << -1 << '\n';
  } else {
    rep(i, 0, n) cout << ans[i] + 1 << ' ';
    cout << '\n';
  }
  return 0;
}