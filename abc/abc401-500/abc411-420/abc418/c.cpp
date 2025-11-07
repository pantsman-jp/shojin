#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  vector<ll> s(n + 1, 0);
  rep(i, n) s[i + 1] = s[i] + a[i];
  rep(_, q)
  {
    int b;
    cin >> b;
    if (a.back() < b)
    {
      cout << -1 << endl;
      continue;
    }
    int i = lower_bound(a.begin(), a.end(), b - 1) - a.begin();
    ll ans = ll(n - i) * (b - 1);
    ans += s[i];
    cout << ans + 1 << endl;
  }
}