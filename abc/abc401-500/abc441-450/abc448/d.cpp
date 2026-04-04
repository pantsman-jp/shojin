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

int n;
vector<int> a;
vector<vector<int>> g;
int cnt = 0;
set<int> s;
vector<int> ans;

void dfs(int v, int pv) {
  int del = 0;
  if (s.find(a[v]) != s.end())
    del = 1;
  else
    s.insert(a[v]);
  cnt += del;
  if (cnt > 0)
    ans[v] = 1;
  else
    ans[v] = 0;
  for (auto& nx : g[v]) {
    if (nx == pv) continue;
    dfs(nx, v);
  }
  cnt -= del;
  if (del == 0) s.erase(a[v]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  a.resize(n), g.resize(n);
  rep(i, 0, n) cin >> a[i];
  rep(_, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  ans.resize(n);
  dfs(0, -1);
  for (int x : ans) yn(x != 0);
  return 0;
}