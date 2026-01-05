#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define ans(p) cout << (p ? "Alice\n" : "Bob\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

void solve()
{
  int n, m, k;
  string s;
  cin >> n >> m >> k >> s;
  vector<vector<int>> g(n);
  rep(i, 0, m)
  {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
  }
  vector dp(2 * k + 1, vector<bool>(n));
  rep(v, 0, n) dp[2 * k][v] = (s[v] == 'A');
  rrep(i, 2 * k, 0) rep(v, 0, n)
  {
    dp[i][v] = 0;
    for (int u : g[v])
    {
      if (!dp[i + 1][u])
        dp[i][v] = true;
    }
  }
  ans(dp[0][0]);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) solve();
}