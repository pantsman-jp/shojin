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

ll eudistance(ll x1, ll y1, ll x2, ll y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool is_cross(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2) {
  ll d = eudistance(x1, y1, x2, y2);
  return abs(r1 - r2) * abs(r1 - r2) <= d and d <= (r1 + r2) * (r1 + r2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  vector<ll> x(n), y(n), r(n);
  rep(i, 0, n) cin >> x[i] >> y[i] >> r[i];
  vector<vector<int>> g(n);
  rep(i, 0, n) rep(j, i + 1, n) {
    if (is_cross(x[i], y[i], r[i], x[j], y[j], r[j]))
      g[i].push_back(j), g[j].push_back(i);
  }
  vector<int> start, goal;
  rep(i, 0, n) {
    if (eudistance(x[i], y[i], sx, sy) == r[i] * r[i]) start.push_back(i);
    if (eudistance(x[i], y[i], tx, ty) == r[i] * r[i]) goal.push_back(i);
  }
  vector<bool> seen(n);
  queue<int> q;
  for (int s : start) {
    seen[s] = true;
    q.push(s);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (!seen[v]) {
        seen[v] = true;
        q.push(v);
      }
    }
  }
  for (int t : goal) {
    if (seen[t]) {
      yn(true);
      return 0;
    }
  }
  yn(false);
  return 0;
}