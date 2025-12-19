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

vector<int> dp;

int solve(int n)
{
  if (n == 0)
    return 0;
  if (dp[n] != -1)
    return dp[n];
  int ans = n;
  for (int pow6 = 1; pow6 <= n; pow6 *= 6)
    chmin(ans, solve(n - pow6) + 1);
  for (int pow9 = 1; pow9 <= n; pow9 *= 9)
    chmin(ans, solve(n - pow9) + 1);
  return dp[n] = ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  dp.resize(n + 1, -1);
  cout << solve(n) << endl;
}