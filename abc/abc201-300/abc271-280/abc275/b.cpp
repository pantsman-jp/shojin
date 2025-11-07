#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

const ll mod = 998244353;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  ll ans = ((a % mod) * (b % mod) % mod * (c % mod)) % mod;
  ans -= ((d % mod) * (e % mod) % mod * (f % mod)) % mod;
  cout << (ans + mod) % mod << endl;
}