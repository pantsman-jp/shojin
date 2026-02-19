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
  set<pii> s;
  int ans = n;
  rep(_, 0, q) {
    int l, r;
    cin >> l >> r;
    l--;
    auto it = s.lower_bound(pii(l, -1));
    if (it != s.begin() and prev(it)->second >= l) it--;
    while (it != s.end() and it->first <= r) {
      ans += it->second - it->first;
      chmin(l, it->first);
      chmax(r, it->second);
      s.erase(it++);
    }
    s.emplace(l, r);
    ans -= r - l;
    cout << ans << endl;
  }
  return 0;
}