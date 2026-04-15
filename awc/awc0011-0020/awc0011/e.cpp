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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  vector<ll> b(n + 1);
  rep(i, 1, n + 1) cin >> a[i] >> b[i];
  vector pre(n + 2, vector<ll>(m + 1));
  vector suf(n + 2, vector<ll>(m + 1));
  rep(i, 1, n + 1) {
    rep(w, 0, m + 1) pre[i][w] = pre[i - 1][w];
    rep(w, a[i], m + 1) chmax(pre[i][w], pre[i - 1][w - a[i]] + b[i]);
  }
  rrep(i, 1, n + 1) {
    rep(w, 0, m + 1) suf[i][w] = suf[i + 1][w];
    rep(w, a[i], m + 1) suf[i][w] = max(suf[i][w], suf[i + 1][w - a[i]] + b[i]);
  }
  ll best = 0;
  rep(w, 0, m + 1) chmax(best, pre[n][w]);
  rep(i, 1, n + 1) {
    ll mx = 0;
    rep(w, 0, m - a[i] + 1) chmax(mx, pre[i - 1][w] + suf[i + 1][m - a[i] - w]);
    yn(mx + b[i] == best);
  }
  return 0;
}