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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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
  int n, k, m;
  cin >> n >> k >> m;
  vector<vector<ll>> gems(n + 1);
  rep(i, 0, n) {
    int c;
    ll v;
    cin >> c >> v;
    gems[c].push_back(v);
  }
  vector<ll> mxs, rest;
  rep(i, 1, n + 1) {
    if (gems[i].empty()) continue;
    sort(rall(gems[i]));
    mxs.push_back(gems[i][0]);
    rep(j, 1, gems[i].size()) rest.push_back(gems[i][j]);
  }
  sort(rall(mxs));
  ll ans = 0;
  rep(i, 0, m) ans += mxs[i];
  rep(i, m, mxs.size()) rest.push_back(mxs[i]);
  sort(rall(rest));
  rep(i, 0, k - m) ans += rest[i];
  cout << ans << '\n';
  return 0;
}