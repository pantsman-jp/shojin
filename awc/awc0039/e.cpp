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
  int n, m, q, k;
  if (!(cin >> n >> m >> q >> k)) return 0;
  vector<pii> ds(m);
  rep(i, 0, m) {
    int s, d;
    cin >> s >> d;
    ds[i] = {d, s - 1};
  }
  sort(rall(ds));
  vector<tuple<int, int, int, int>> queries(q);
  rep(i, 0, q) {
    int l, r, t;
    cin >> l >> r >> t;
    queries[i] = {t, l - 1, r, i};
  }
  sort(rall(queries));
  vector<int> ans(q);
  fenwick_tree<int> fw(n);
  int book_idx = 0;
  for (auto [t, l, r, id] : queries) {
    while (book_idx < m and ds[book_idx].first >= t) {
      fw.add(ds[book_idx].second, 1);
      book_idx++;
    }
    int count = fw.sum(l, r);
    ans[id] = max(0, count - k);
  }
  rep(i, 0, q) cout << ans[i] << '\n';
  return 0;
}