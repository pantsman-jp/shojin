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
  int n, k;
  cin >> n >> k;
  vector<ll> a(k), frontsum(k + 1), backsum(k + 1);
  rep(i, 0, k) cin >> a[i];
  rep(i, 1, k + 1)
  {
    frontsum[i] = frontsum[i - 1];
    if (i % 2 == 0)
      frontsum[i] += a[i - 1] - a[i - 2];
  }
  for (int i = k - 1; i >= 0; i--)
  {
    backsum[i] = backsum[i + 1];
    if ((k - i) % 2 == 0)
      backsum[i] += a[i + 1] - a[i];
  }
  ll ans = inf;
  for (int i = 0; i <= k; i += 2)
    ans = min(ans, frontsum[i] + backsum[i]);
  cout << ans << endl;
}