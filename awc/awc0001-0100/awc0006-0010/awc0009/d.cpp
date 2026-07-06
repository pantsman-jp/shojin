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
  ll n;
  int m;
  cin >> n >> m;
  vector<pll> lr(m);
  rep(i, 0, m) cin >> lr[i].first >> lr[i].second;
  sort(all(lr));
  vector<pll> seg;
  rep(i, 0, m) {
    if (seg.empty() or seg.back().second < lr[i].first - 1)
      seg.push_back(lr[i]);
    else
      chmax(seg.back().second, lr[i].second);
  }
  ll now = 1;
  for (auto [l, r] : seg) {
    if (now < l) {
      ll len = l - now;
      if (n <= len) {
        cout << now + n - 1 << "\n";
        return 0;
      }
      n -= len;
    }
    now = r + 1;
  }
  cout << now + n - 1 << endl;
  return 0;
}