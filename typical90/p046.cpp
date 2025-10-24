#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  map<ll, ll> a, b, c;
  rep(i, 0, n)
  {
    ll x;
    cin >> x;
    a[x % 46]++;
  }
  rep(i, 0, n)
  {
    ll x;
    cin >> x;
    b[x % 46]++;
  }
  rep(i, 0, n)
  {
    ll x;
    cin >> x;
    c[x % 46]++;
  }
  ll ans = 0;
  rep(i, 0, 46)
  {
    rep(j, 0, 46)
    {
      rep(k, 0, 46)
      {
        if ((i + j + k) % 46 == 0)
          ans += a[i] * b[j] * c[k];
      }
    }
  }
  cout << ans << endl;
}
