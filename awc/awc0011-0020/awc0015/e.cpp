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
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  rep(i, 0, n) cin >> p[i], p[i]--;
  vector<tuple<int, int, int>> qs(q);
  rep(i, 0, q) {
    int l, r;
    cin >> l >> r;
    qs[i] = {r, l - 1, i};
  }
  ranges::sort(qs);
  fenwick_tree<int> fw(n);
  vector<int> ans(q), prev(n, -1);
  int now = 0;
  for (auto [r, l, idx] : qs) {
    while (now < r) {
      int x = p[now];
      if (prev[x] != -1) fw.add(prev[x], -1);
      fw.add(now, 1);
      prev[x] = now;
      now++;
    }
    ans[idx] = fw.sum(l, r);
  }
  rep(i, 0, q) cout << ans[i] << '\n';
  return 0;
}