#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll x;
  cin >> n >> x;
  vector<vector<ll>> a(n);
  rep(i, 0, n)
  {
    int l;
    cin >> l;
    a[i].resize(l);
    rep(j, 0, l) cin >> a[i][j];
  }
  vector<unordered_map<ll, ll>> dp(n + 1);
  dp[0][1] = 1;
  rep(i, 0, n)
  {
    for (auto &p : dp[i])
    {
      auto [v, c] = p;
      for (ll val : a[i])
      {
        if (v <= x / val)
          dp[i + 1][v * val] += c;
      }
    }
  }
  if (dp[n].count(x) != 0)
    cout << dp[n][x] << endl;
  else
    cout << 0 << endl;
}