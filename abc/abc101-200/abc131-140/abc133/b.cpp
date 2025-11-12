#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_square(ll n)
{
  for (ll i = 1; i * i <= n; i++)
    if (i * i == n)
      return true;
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, d;
  cin >> n >> d;
  vector<vector<ll>> x(n, vector<ll>(d));
  rep(i, 0, n) rep(j, 0, d) cin >> x[i][j];
  ll ans = 0;
  rep(i, 0, n) rep(j, i + 1, n)
  {
    ll dd = 0;
    rep(k, 0, d) dd += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
    if (is_square(dd))
      ans++;
  }
  cout << ans << endl;
}