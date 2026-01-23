#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ll mod = 998244353;
// const ll mod = 1000000007;

ll modpow(ll a, ll b, ll mod)
{
  ll ans = 1;
  while (b > 0)
  {
    if ((b & 1) != 0)
      ans = ans * a % mod;
    a = a * a % mod, b >>= 1;
  }
  return ans;
}

ll div(ll a, ll b, ll m)
{
  return (a * modpow(b, m - 2, m)) % m;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll d = to_string(n).size();
  ll pow10 = modpow(10, d, mod);
  ll num = (modpow(pow10, n, mod) - 1 + mod) % mod;
  ll den = (pow10 - 1 + mod) % mod;
  ll invden = modpow(den, mod - 2, mod);
  ll ans = n % mod;
  ans = ans * num % mod;
  ans = ans * invden % mod;
  cout << ans << endl;
}