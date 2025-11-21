#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, d, p;
  cin >> n >> d >> p;
  vector<ll> f(n), sum(n + 1);
  rep(i, 0, n) cin >> f[i];
  sort(all(f), greater<ll>());
  sum[0] = 0;
  rep(i, 0, n) sum[i + 1] = sum[i] + f[i];
  ll ans = inf;
  rep(i, 0, (n + d - 1) / d + 1) ans = min(ans, sum[n] - sum[min(n, i * d)] + p * i);
  cout << ans << endl;
}