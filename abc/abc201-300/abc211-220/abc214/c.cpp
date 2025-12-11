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
  cin >> n;
  vector<int> s(n), t(n);
  rep(i, 0, n) cin >> s[i];
  rep(i, 0, n) cin >> t[i];
  vector<int> dp = t;
  rep(i, 0, 2 * n) dp[(i + 1) % n] = min(dp[(i + 1) % n], dp[i % n] + s[i % n]);
  rep(i, 0, n) cout << dp[i] << endl;
}