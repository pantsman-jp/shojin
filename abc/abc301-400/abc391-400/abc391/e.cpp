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
  int n;
  string s;
  cin >> n >> s;
  vector dp(s.size(), vector<int>(2, 1));
  rep(i, 0, s.size()) dp[i][s[i] - '0'] = 0;
  while (dp.size() > 1) {
    vector old(dp.size() / 3, vector<int>(2, inf));
    swap(dp, old);
    for (int l = 0; l < old.size(); l += 3) {
      rep(i, 0, 8) {
        int cost = 0;
        rep(j, 0, 3) cost += old[l + j][i >> j & 1];
        int x = __builtin_popcount(i) >= 2 ? 1 : 0;
        chmin(dp[l / 3][x], cost);
      }
    }
  }
  cout << max(dp[0][0], dp[0][1]) << endl;
  return 0;
}