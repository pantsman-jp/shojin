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
// const ll mod = 998244353;
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector dp(2, vector<ll>(n + 1));
  dp[0][0] = 0, dp[1][0] = -INF;
  rep(i, 0, n)
  {
    dp[0][i + 1] = max(dp[0][i], dp[1][i] + 2 * a[i]);
    dp[1][i + 1] = max(dp[0][i] + a[i], dp[1][i]);
  }
  cout << max(dp[0][n], dp[1][n]) << endl;
}