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
  int n, k;
  cin >> n >> k;
  vector<ll> t(k), p(k);
  rep(i, 0, k) cin >> t[i] >> p[i];
  ll s = 0;
  vector<ll> c(n);
  rep(i, 0, n) {
    cin >> c[i];
    s += c[i];
  }
  ll ans = s;
  rep(i, 0, k) {
    ll max_x = s;
    if (i + 1 < k) chmin(max_x, t[i + 1] - 1);
    if (max_x >= t[i]) chmin(ans, s - ((max_x * p[i]) / 100));
  }
  cout << ans << '\n';
  return 0;
}