#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
const ll mod = 1e9 + 7;

ll modpow(ll a, ll b, ll mod)
{
  ll ans = 1;
  while (b > 0)
  {
    if (b & 1)
      ans = ans * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll ans = modpow(10, n, mod);
  ans = (ans - modpow(9, n, mod) * 2 % mod + mod) % mod;
  ans = (ans + modpow(8, n, mod)) % mod;
  cout << ans << endl;
}