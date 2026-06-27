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
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<int> u(m), v(m);
  vector<ll> b(m);
  rep(i, 0, m) {
    cin >> u[i] >> v[i] >> b[i];
    u[i]--, v[i]--;
  }
  ll ans = -INF;
  rep(i, 0, 1 << n) {
    if (__builtin_popcount(i) != k) continue;
    ll sum = 0;
    rep(j, 0, n) if (i & (1 << j)) sum += a[j];
    ll minus = 0;
    rep(j, 0, m) if ((i & (1 << u[j])) and (i & (1 << v[j]))) minus += b[j];
    chmax(ans, sum - minus);
  }
  cout << ans << '\n';
  return 0;
}