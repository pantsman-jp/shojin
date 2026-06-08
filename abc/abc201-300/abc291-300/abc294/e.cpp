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
  ll l;
  int n1, n2;
  cin >> l >> n1 >> n2;
  vector<pll> top, bottom;
  rep(_, 0, n1) {
    ll v1, l1;
    cin >> v1 >> l1;
    top.emplace_back(v1, l1);
  }
  rep(_, 0, n2) {
    ll v2, l2;
    cin >> v2 >> l2;
    bottom.emplace_back(v2, l2);
  }
  ll i = 0, j = 0, ans = 0;
  while (i < n1 and j < n2) {
    auto& [v1, l1] = top[i];
    auto& [v2, l2] = bottom[j];
    ll overlap = min(l1, l2);
    if (v1 == v2) ans += overlap;
    l1 -= overlap;
    l2 -= overlap;
    if (l1 == 0) i++;
    if (l2 == 0) j++;
  }
  cout << ans << '\n';
  return 0;
}