#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n), v;
  rep(i, 0, n)
  {
    cin >> a[i] >> b[i];
    v.push_back(b[i]), v.push_back(a[i] - b[i]);
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  rep(i, 0, k) ans += v[i];
  cout << ans << endl;
}
