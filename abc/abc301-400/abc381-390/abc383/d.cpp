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
// const ll mod = 998244353;
// const ll mod = 1000000007;

vector<__int128> primes(ll n)
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
  vector<__int128> ans;
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
  ll ans = 0;
  vector<__int128> prime = primes((ll)sqrt(n) + 1);
  for (__int128 p : prime)
  {
    __int128 v = 1;
    rep(i, 0, 8) v *= p;
    if (v <= n)
      ++ans;
    else
      break;
  }
  int m = prime.size();
  rep(i, 0, m) rep(j, i + 1, m)
  {
    __int128 v = prime[i] * prime[i] * prime[j] * prime[j];
    if (v <= n)
      ++ans;
    else
      break;
  }
  cout << ans << endl;
}