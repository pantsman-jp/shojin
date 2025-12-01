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
  ll n;
  cin >> n;
  vector<ll> num(n + 1, 0);
  rep(x, 1, n + 1)
  {
    for (ll y = 1; x * y <= n; ++y)
      num[x * y]++;
  }
  ll ans = 0;
  rep(v, 1, n + 1) ans += num[v] * num[n - v];
  cout << ans << endl;
}