#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

vector<bool> era(ll n)
{
  vector<bool> is_prime(n + 2, true);
  is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i <= n; i++)
  {
    if (is_prime[i])
    {
      for (ll j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
  }
  return is_prime;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<bool> is_prime = era(1e6 + 1);
  ll ans = 0;
  vector<ll> sum(1e6 + 1, 0);
  rep(i, 0, 1e6) sum[i + 1] = sum[i] + (is_prime[i] ? 1 : 0);
  for (ll a = 1; a * a * a * a * a <= n; a++)
  {
    if (!is_prime[a])
      continue;
    for (ll b = a + 1; b * b * b <= n; b++)
    {
      if (!is_prime[b])
        continue;
      ll cmax = sqrt(n / a / a / b);
      if (b + 1 <= cmax + 1)
        ans += sum[cmax + 1] - sum[b + 1];
    }
  }
  cout << ans << endl;
}