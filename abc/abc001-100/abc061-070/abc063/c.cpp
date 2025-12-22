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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, 0, n) cin >> s[i];
  vector<bool> dp(1e4 + 1, false);
  dp[0] = true;
  rep(i, 0, n) rrep(x, 1e4 + 1, s[i]) if (dp[x - s[i]]) dp[x] = true;
  int ans = 0;
  rep(x, 1, 1e4 + 1) if (dp[x] and x % 10 != 0) chmax(ans, x);
  cout << ans << endl;
}