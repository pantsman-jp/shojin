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
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  vector<int> dp(n);
  dp[0] = 0, dp[1] = abs(h[0] - h[1]);
  rep(i, 2, n)
  {
    int best = inf;
    rep(j, 1, k + 1)
    {
      if (i - j < 0)
        break;
      chmin(best, dp[i - j] + abs(h[i] - h[i - j]));
    }
    dp[i] = best;
  }
  cout << dp.back() << endl;
}