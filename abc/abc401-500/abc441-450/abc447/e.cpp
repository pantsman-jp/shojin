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
using mint = modint998244353;
// using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> u(m + 1), v(m + 1);
  rep(i, 1, m + 1) {
    cin >> u[i] >> v[i];
    u[i]--, v[i]--;
  }
  dsu uf(n);
  vector<vector<pii>> g(n);
  int mn = m + 1;
  rrep(i, 1, m + 1) {
    if (uf.same(u[i], v[i])) continue;
    uf.merge(u[i], v[i]);
    g[u[i]].emplace_back(v[i], i);
    g[v[i]].emplace_back(u[i], i);
    mn = i;
  }
  vector<int> group(n, -1);
  queue<int> q;
  q.push(u[mn]);
  group[u[mn]] = 0;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto [nxt, idx] : g[now]) {
      if (idx == mn or group[nxt] != -1) continue;
      group[nxt] = 0;
      q.push(nxt);
    }
  }
  rep(i, 0, n) if (group[i] == -1) group[i] = 1;
  vector<mint> pow2(m + 1, 1);
  rep(i, 0, m) pow2[i + 1] = pow2[i] * 2;
  mint ans = 0;
  rep(i, 1, m + 1) if (group[u[i]] != group[v[i]]) ans += pow2[i];
  cout << ans.val() << endl;
  return 0;
}