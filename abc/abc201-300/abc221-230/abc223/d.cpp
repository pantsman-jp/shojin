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

vector<int> topo_sort(vector<vector<int>> g) {
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
    a--, b--;
    g[a].push_back(b);
  }
  vector<int> ans = topo_sort(g);
  if (ans.size() < n)
    cout << -1 << endl;
  else {
    for (auto x : ans) cout << x + 1 << " ";
    cout << endl;
  }
  return 0;
}