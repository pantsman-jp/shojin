#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, p, q;
  cin >> n >> p >> q;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  ll ans = 0;
  rep(i, 0, n)
  {
    rep(j, 0, i)
    {
      rep(k, 0, j)
      {
        rep(l, 0, k)
        {
          rep(m, 0, l)
          {
            if (a[i] * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q)
              ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
