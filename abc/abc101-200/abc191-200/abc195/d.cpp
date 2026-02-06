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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> w(n), v(n);
  rep(i, 0, n) cin >> w[i] >> v[i];
  vector<int> x(m);
  rep(i, 0, m) cin >> x[i];
  rep(_, 0, q) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    vector<int> box;
    rep(i, 0, m) if (i < l or r < i) box.push_back(x[i]);
    sort(all(box));
    vector<bool> used(n);
    int ans = 0;
    for (int capa : box) {
      pii best = {-1, -1};
      rep(i, 0, n) if (!used[i] and w[i] <= capa) {
        chmax(best, make_pair(v[i], i));
      }
      int i = best.second;
      if (i != -1) {
        used[i] = true;
        ans += v[i];
      }
    }
    cout << ans << endl;
  }
  return 0;
}