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
  vector<int> a(n), b(n), c(n);
  rep(i, 0, n) cin >> a[i] >> b[i] >> c[i];
  vector dp(3, vector<int>(n));
  dp[0][0] = a[0], dp[1][0] = b[0], dp[2][0] = c[0];
  rep(i, 1, n)
  {
    dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + a[i];
    dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + b[i];
    dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + c[i];
  }
  cout << max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1])) << endl;
}