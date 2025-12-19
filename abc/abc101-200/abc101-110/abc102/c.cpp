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
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i], a[i] -= i + 1;
  sort(all(a));
  ll b = a[n / 2], ans = 0;
  rep(i, 0, n) ans += abs(a[i] - b);
  cout << ans << endl;
}