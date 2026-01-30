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
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

bool is_dag(vector<vector<int>> g) {
  int n = g.size();
  vector<int> state(n, 0);
  auto dfs = [&](auto self, int u) -> bool {
    state[u] = 1;
    for (int v : g[u]) {
      if (state[v] == 1) return false;
      if (state[v] == 0 and !self(self, v)) return false;
    }
    state[u] = 2;
    return true;
  };
  rep(i, 0, n) if (state[i] == 0 and !dfs(dfs, i)) return false;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  unordered_map<string, int> id;
  int cur = 0;
  auto get_id = [&](const string& s) {
    if (!id.count(s)) id[s] = cur++;
    return id[s];
  };
  vector<vector<int>> g(2 * n);
  rep(_, 0, n) {
    string s, t;
    cin >> s >> t;
    int u = get_id(s), v = get_id(t);
    g[u].push_back(v);
  }
  yn(is_dag(g));
  return 0;
}