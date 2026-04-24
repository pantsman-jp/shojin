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
  vector<ll> d(n), s(m);
  rep(i, 0, n) cin >> d[i];
  rep(i, 0, m) cin >> s[i];
  sort(all(s));
  ll ans = 0;
  rep(i, 0, n) {
    auto it = lower_bound(all(s), d[i]);
    ll cost = INF;
    if (it != s.end()) chmin(cost, abs(d[i] - *it));
    if (it != s.begin()) chmin(cost, abs(d[i] - *prev(it)));
    ans += cost;
  }
  cout << ans << '\n';
  return 0;
}