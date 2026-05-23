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
  vector<int> cnt(n);
  fenwick_tree<int> ft(q + 2);
  ft.add(0, n);
  int offset = 0;
  rep(_, 0, q) {
    int t, x, y;
    cin >> t;
    if (t == 1) {
      cin >> x;
      x--;
      ft.add(cnt[x], -1);
      cnt[x]++;
      ft.add(cnt[x], 1);
      if (ft.sum(offset, offset + 1) == 0) {
        offset++;
      }
    } else {
      cin >> y;
      if (y + offset > q + 1) {
        cout << 0 << '\n';
      } else {
        cout << n - ft.sum(0, y + offset) << '\n';
      }
    }
  }
  return 0;
}