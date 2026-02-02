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
#define yn(tf) cout << (tf ? "Yes\n" : "No\n");
#define dout(x) cout << fixed << setprecision(10) << x << "\n";
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
  int n, s;
  cin >> n >> s;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];
  vector dp(n + 1, vector<bool>(s + 1));
  dp[0][0] = true;
  rep(i, 0, n) rep(j, 0, s + 1) if (dp[i][j]) {
    if (j + a[i] <= s) dp[i + 1][j + a[i]] = true;
    if (j + b[i] <= s) dp[i + 1][j + b[i]] = true;
  }
  if (!dp[n][s]) {
    cout << "No" << endl;
    return 0;
  }
  string ans = "";
  rrep(i, 0, n) {
    if (s - a[i] >= 0 and dp[i][s - a[i]]) {
      s -= a[i];
      ans += 'H';
    } else {
      s -= b[i];
      ans += 'T';
    }
  }
  reverse(all(ans));
  cout << "Yes\n" + ans << endl;
  return 0;
}