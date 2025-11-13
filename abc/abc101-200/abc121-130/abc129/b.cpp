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
  ll n;
  cin >> n;
  vector<ll> w(n), sum(n + 1);
  rep(i, 0, n) cin >> w[i];
  sum[0] = 0;
  rep(i, 0, n) sum[i + 1] = sum[i] + w[i];
  ll ans = inf;
  rep(t, 0, n - 1) ans = min(ans, abs(sum[t + 1] - (sum[n] - sum[t + 1])));
  cout << ans << endl;
}