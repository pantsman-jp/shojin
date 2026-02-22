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
  int t;
  cin >> t;
  rep(_, 0, t) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n), b(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    deque<pii> q;
    rep(i, 0, n) {
      q.push_back({i, a[i]});
      int need = b[i];
      while (need > 0 and !q.empty()) {
        if (q.front().second > need) {
          q.front().second -= need;
          need = 0;
        } else {
          need -= q.front().second;
          q.pop_front();
        }
      }
      while (!q.empty() and q.front().first <= i - d) q.pop_front();
    }
    ll ans = 0;
    for (auto [_, cnt] : q) ans += cnt;
    cout << ans << endl;
  }
  return 0;
}