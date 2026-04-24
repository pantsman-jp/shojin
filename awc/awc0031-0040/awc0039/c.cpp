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
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n), b(n), suma(n + 1), sumb(n + 1);
  rep(i, 0, n) cin >> a[i], suma[i + 1] = suma[i] + a[i];
  rep(i, 0, n) cin >> b[i], sumb[i + 1] = sumb[i] + b[i];
  ll ans = 0;
  rep(l, 1, n + 1) {
    auto it = upper_bound(all(sumb), sumb[l - 1] + k);
    int r = distance(sumb.begin(), it) - 1;
    if (r >= l) chmax(ans, suma[r] - suma[l - 1]);
  }
  cout << ans << '\n';
  return 0;
}