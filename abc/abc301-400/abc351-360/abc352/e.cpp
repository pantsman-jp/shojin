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
  vector<tuple<int, int, int>> g;
  rep(i, 0, m) {
    int k, c;
    cin >> k >> c;
    vector<int> a(k);
    rep(j, 0, k) cin >> a[j], a[j]--;
    rep(j, 0, k - 1) g.emplace_back(c, a[j], a[j + 1]);
  }
  sort(all(g));
  dsu uf(n);
  ll ans = 0;
  for (auto [c, a, b] : g) {
    if (uf.same(a, b)) continue;
    uf.merge(a, b);
    ans += c;
  }
  if (uf.size(0) != n) ans = -1;
  cout << ans << '\n';
  return 0;
}