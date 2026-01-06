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
  vector dp(N + 1, vector<ll>(W + 1, -INF));
  dp[0][0] = 0;
  rep(i, 1, N + 1) rep(j, 0, W + 1)
  {
    if (j < w[i])
      dp[i][j] = dp[i - 1][j];
    else
      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
  }
  cout << *max_element(all(dp[N])) << endl;
}