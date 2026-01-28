#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n), z(n);
  rep(i, 0, n) cin >> x[i] >> y[i] >> z[i];
  int sum = accumulate(all(z), 0);
  vector<ll> dp(sum + 1, INF);
  dp[0] = 0;
  rep(i, 0, n)
  {
    int need = max(0, (x[i] + y[i]) / 2 + 1 - x[i]);
    rrep(j, z[i], sum + 1) chmin(dp[j], dp[j - z[i]] + need);
  }
  ll ans = INF;
  rep(i, sum / 2 + 1, sum + 1) chmin(ans, dp[i]);
  cout << ans << endl;
}