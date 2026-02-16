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
  int n, Q;
  cin >> n >> Q;
  vector<vector<int>> g(n);
  rep(_, 0, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b), g[b].push_back(a);
  }
  vector<ll> ans(n);
  rep(_, 0, Q) {
    int p;
    ll x;
    cin >> p >> x;
    ans[p - 1] += x;
  }
  queue<int> q;
  vector<bool> seen(n);
  q.push(0), seen[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    seen[u] = true;
    for (int v : g[u]) {
      if (seen[v]) continue;
      ans[v] += ans[u];
      q.push(v);
      seen[v] = true;
    }
  }
  for (ll x : ans) cout << x << " ";
  cout << endl;
  return 0;
}