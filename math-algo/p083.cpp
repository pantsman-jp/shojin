#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(array) array.begin(), array.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  sort(all(a)), sort(all(b));
  ll ans = 0;
  rep(i, 0, n) ans += abs(a[i] - b[i]);
  cout << ans << endl;
}