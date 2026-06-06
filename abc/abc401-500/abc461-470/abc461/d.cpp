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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector a(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) a[i][j] = s[i][j] - '0';
  vector sum(h + 1, vector<int>(w + 1));
  rep(i, 0, h) rep(j, 0, w) {
    sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + a[i][j];
  }
  ll ans = 0;
  rep(i1, 0, h) rep(i2, i1 + 1, h + 1) {
    vector<int> cnt(h * w + 1);
    rep(j, 0, w + 1) {
      int nowsum = sum[i2][j] - sum[i1][j];
      int target = nowsum - k;
      if (0 <= target and target <= h * w) ans += cnt[target];
      if (nowsum <= h * w) cnt[nowsum]++;
    }
  }
  cout << ans << '\n';
  return 0;
}