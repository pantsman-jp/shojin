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

ll eudist(ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s, t;
  ll d;
  cin >> n >> d >> s >> t;
  s--, t--;
  vector<pll> xy(n);
  rep(i, 0, n) {
    ll x, y;
    cin >> x >> y;
    xy[i] = {x, y};
  }
  vector<vector<int>> g(n);
  rep(i, 0, n) rep(j, 0, n) {
    if (i == j) continue;
    auto [xi, yi] = xy[i];
    auto [xj, yj] = xy[j];
    if (eudist(xi, yi, xj, yj) <= d * d) {
      g[i].push_back(j);
      g[j].push_back(i);
    }
  }
  queue<int> q;
  q.push(s);
  vector<int> dist(n, -1);
  dist[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (dist[v] != -1) continue;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
  cout << dist[t] << '\n';
  return 0;
}