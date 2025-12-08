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
  ll k, x;
  cin >> n >> k >> x;
  vector<ll> a(n), rem(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n)
  {
    ll use = min(k, a[i] / x);
    k -= use;
    rem.push_back(a[i] - use * x);
  }
  sort(all(rem), greater<ll>());
  ll ans = 0;
  rep(i, 0, n)
  {
    if (k > 0)
      k--;
    else
      ans += rem[i];
  }
  cout << ans << endl;
}