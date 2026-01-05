#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  rep(i, 0, n) cin >> c[i];
  vector dp(n + 1, vector<ll>(4));
  rep(i, 0, n + 1) rep(j, 0, 4) dp[i][j] = -INF;
  dp[0][0] = 0;
  rep(i, 0, n)
  {
    rep(j, 0, 2) chmax(dp[i + 1][1], dp[i][j] + a[i]);
    rep(j, 1, 3) chmax(dp[i + 1][2], dp[i][j] + b[i]);
    rep(j, 2, 4) chmax(dp[i + 1][3], dp[i][j] + c[i]);
  }
  cout << dp[n][3] << endl;
}