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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 2);
  rep(i, 1, n + 1) cin >> a[i];
  vector<vector<int>> groups(k);
  rep(i, 1, n + 2) if (a[i] ^ a[i - 1] == 1) groups[i % k].push_back(i);
  ll ans = 0;
  rep(r, 0, k) {
    if (groups[r].size() % 2 != 0) {
      cout << -1 << '\n';
      return 0;
    }
    for (int i = 0; i < groups[r].size(); i += 2)
      ans += (groups[r][i + 1] - groups[r][i]) / k;
  }
  cout << ans << '\n';
  return 0;
}