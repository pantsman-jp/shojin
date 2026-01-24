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

ll digit(ll n)
{
  return (ll)to_string(n).size();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> d(11);
  rep(i, 0, n) d[digit(a[i])]++;
  vector<ll> pow10(11);
  rep(i, 1, 11) pow10[i] = modpow(10, i, mod);
  ll ans = 0;
  rep(i, 0, n) ans = (ans + a[i] * i) % mod;
  rep(i, 0, n)
  {
    d[digit(a[i])]--;
    rep(j, 1, 11)
    {
      ll term = (a[i] * pow10[j]) % mod;
      ans = (ans + term * d[j]) % mod;
    }
  }
  cout << ans << endl;
}