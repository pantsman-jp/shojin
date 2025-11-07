#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;
const ll mod = 1e9;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n + 1), sum(n + 1);
  sum[0] = 0;
  rep(i, 0, n + 1)
  {
    if (i < k)
      a[i] = 1;
    else
      a[i] = (sum[i] - sum[i - k] + mod) % mod;
    sum[i + 1] = (sum[i] + a[i] + mod) % mod;
  }
  cout << a[n] << endl;
}