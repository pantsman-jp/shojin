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
// const ll mod = 1e9 + 7;

int solve(const vector<int> &a)
{
  int n = a.size();
  vector<vector<int>> dp(n + 1, vector<int>(2));
  rep(i, 0, n)
  {
    dp[i + 1][0] = max(dp[i][0], dp[i][1]);
    dp[i + 1][1] = dp[i][0] + a[i];
  }
  int mx = max(dp[n][0], dp[n][1]);
  int sum = 0;
  rep(i, 0, n) sum += a[i];
  return sum - mx;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d;
  cin >> n >> d;
  const int M = 1000001;
  vector<int> cnt(M);
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    cnt[a]++;
  }
  int ans = 0;
  if (d == 0)
  {
    rep(i, 0, M) if (cnt[i] > 0)
        ans += cnt[i] - 1;
  }
  else
  {
    rep(si, 0, d)
    {
      vector<int> a;
      for (int i = si; i < M; i += d)
        a.push_back(cnt[i]);
      ans += solve(a);
    }
  }
  cout << ans << endl;
}