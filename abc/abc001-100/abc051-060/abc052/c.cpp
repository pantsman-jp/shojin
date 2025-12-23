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
const ll mod = 1e9 + 7;

bool is_prime(ll n)
{
  if (n < 2)
    return false;
  for (ll i = 2; i * i <= n; i++)
  {
    if (n % i == 0)
      return false;
  }
  return true;
}

vector<ll> primes(ll n)
{
  vector<bool> prime(n + 2, true);
  prime[0] = prime[1] = false;
  for (ll i = 2; i * i <= n; i++)
  {
    if (prime[i])
    {
      for (ll x = i * i; x <= n; x += i)
        prime[x] = false;
    }
  }
  vector<ll> ans;
  for (ll i = 2; i <= n; i++)
  {
    if (prime[i])
      ans.push_back(i);
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> ps = primes(n);
  ll ans = 1;
  for (ll p : ps)
  {
    ll e = 0;
    for (ll x = p; x <= n; x *= p)
      e += n / x;
    ans = ans * (e + 1) % mod;
  }
  cout << ans << endl;
}