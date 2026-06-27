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

pll coord(ll x, ll n) { return {(x - 1) / n, (x - 1) % n}; }

ll dist(pll a, pll b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  int m;
  cin >> n >> m;
  ll s, t;
  cin >> s >> t;
  vector<ll> p(m);
  rep(i, 0, m) cin >> p[i];
  auto cs = coord(s, n);
  auto ct = coord(t, n);
  if (m == 0) {
    cout << dist(cs, ct) << endl;
    return 0;
  }
  vector<pll> cp(m);
  rep(i, 0, m) cp[i] = coord(p[i], n);
  vector dp(1 << m, vector<ll>(m, INF));
  rep(i, 0, m) dp[1 << i][i] = dist(cs, cp[i]);
  for (int mask = 0; mask < (1 << m); mask++) {
    rep(i, 0, m) {
      if (!(mask & (1 << i)) or dp[mask][i] == INF) continue;
      rep(j, 0, m) {
        if (mask & (1 << j)) continue;
        int nmask = mask | (1 << j);
        chmin(dp[nmask][j], dp[mask][i] + dist(cp[i], cp[j]));
      }
    }
  }
  ll ans = INF;
  int full = (1 << m) - 1;
  rep(i, 0, m) chmin(ans, dp[full][i] + dist(cp[i], ct));
  cout << ans << endl;
  return 0;
}