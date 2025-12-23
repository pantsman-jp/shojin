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
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  ll ans = 0;
  rep(i, 0, n - 1)
  {
    if (a[i] + a[i + 1] <= x)
      continue;
    if (a[i] > x)
      ans += a[i] - x, a[i] = x;
    ll eat = a[i] + a[i + 1] - x;
    ans += eat, a[i + 1] -= eat;
  }
  cout << ans << endl;
}