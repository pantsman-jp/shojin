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
  int N, W;
  cin >> N >> W;
  vector<ll> w(N + 1), v(N + 1);
  rep(i, 1, N + 1) cin >> w[i] >> v[i];
  ll sumv = accumulate(all(v), 0LL);
  vector<ll> dp(sumv + 1, INF);
  dp[0] = 0;
  rep(i, 1, N + 1)
  {
    for (ll x = sumv; x >= v[i]; x--)
      dp[x] = min(dp[x], dp[x - v[i]] + w[i]);
  }
  ll ans = 0;
  for (ll x = 0; x <= sumv; x++)
    if (dp[x] <= W)
      ans = x;
  cout << ans << endl;
}