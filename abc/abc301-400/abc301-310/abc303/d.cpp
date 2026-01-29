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
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll x, y, z;
  string s;
  cin >> x >> y >> z >> s;
  int n = s.size();
  vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
  dp[0][0] = 0;
  rep(i, 0, n)
  {
    chmin(dp[i][0], dp[i][1] + z);
    chmin(dp[i][1], dp[i][0] + z);
    if (s[i] == 'a')
    {
      chmin(dp[i + 1][0], dp[i][0] + x);
      chmin(dp[i + 1][1], dp[i][1] + y);
    }
    else
    {
      chmin(dp[i + 1][0], dp[i][0] + y);
      chmin(dp[i + 1][1], dp[i][1] + x);
    }
  }
  cout << min(dp[n][0], dp[n][1]) << endl;
}