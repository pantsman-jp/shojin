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

ll fact(ll n, ll mod)
{
  ll ans = 1;
  for (ll m = 1; m <= n; m++)
    ans = ans * m % mod;
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  ll ans = fact(n, mod) * fact(m, mod) % mod;
  if (abs(n - m) >= 2)
    cout << 0 << endl;
  else if (abs(n - m) == 1)
    cout << ans << endl;
  else
    cout << ans * 2 % mod << endl;
}