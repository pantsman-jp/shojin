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
  int n;
  cin >> n;
  ll h = 0, ans = 0;
  stack<pii> st;
  rep(_, 0, n) {
    int d, v;
    cin >> d >> v;
    if (h < d) {
      st.push({d, v});
    } else {
      h += d, ans += v;
      while (!st.empty()) {
        auto [d1, v1] = st.top();
        if (d1 <= h)
          h += d1, ans += v, st.pop();
        else
          break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}