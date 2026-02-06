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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  rep(_, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<int> color(n, -1);
  queue<int> que;
  color[0] = 0;
  que.push(0);
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (int v : g[u]) {
      if (color[v] != -1) continue;
      color[v] = (color[u] + 1) % 2;
      que.push(v);
    }
  }
  rep(_, 0, q) {
    int c, d;
    cin >> c >> d;
    c--, d--;
    if ((color[c] + color[d]) % 2 == 0)
      cout << "Town" << endl;
    else
      cout << "Road" << endl;
  }
  return 0;
}