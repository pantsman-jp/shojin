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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  sort(all(b));
  vector<ll> sum(m + 1);
  rep(i, 0, m) sum[i + 1] = (sum[i] + b[i]) % mod;
  ll ans = 0;
  rep(i, 0, n)
  {
    ll j = upper_bound(all(b), a[i]) - b.begin();
    ll l = ((j * a[i]) % mod - sum[j] + mod) % mod;
    ll r = ((sum[m] - sum[j] - (m - j) * a[i]) % mod + mod) % mod;
    ans = (ans + l + r) % mod;
  }
  cout << ans << endl;
}