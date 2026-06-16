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
  vector<pii> pos(n);
  set<pii> s;
  rep(i, 0, n) {
    int x, y;
    cin >> x >> y;
    s.insert({x, y});
    pos[i] = {x, y};
  }
  ll ans = 0;
  rep(i, 0, n) rep(j, i + 1, n) {
    auto [x1, y1] = pos[i];
    auto [x2, y2] = pos[j];
    if (x1 != x2 and y1 != y2) {
      if (s.count({x1, y2}) == 1 and s.count({x2, y1}) == 1) ans++;
    }
  }
  cout << ans / 2 << '\n';
  return 0;
}