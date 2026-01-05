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
  vector<int> w(n), h(n), b(n);
  int sum = 0;
  rep(i, 0, n) cin >> w[i] >> h[i] >> b[i], sum += w[i];
  vector<ll> dp(2 * sum + 1, -INF);
  dp[sum] = 0;
  rep(i, 0, n)
  {
    vector<ll> ndp(2 * sum + 1, -INF);
    rep(diff, 0, 2 * sum + 1)
    {
      if (dp[diff] < 0)
        continue;
      if (diff + w[i] <= 2 * sum)
        chmax(ndp[diff + w[i]], dp[diff] + h[i]);
      if (diff - w[i] >= 0)
        chmax(ndp[diff - w[i]], dp[diff] + b[i]);
    }
    dp.swap(ndp);
  }
  ll ans = 0;
  rep(diff, 0, sum + 1) chmax(ans, dp[diff]);
  cout << ans << endl;
}