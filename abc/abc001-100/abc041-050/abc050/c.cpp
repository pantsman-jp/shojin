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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  map<int, ll> cnta;
  for (int x : a)
    cnta[x]++;
  map<int, ll> cntb;
  rep(k, 1, n + 1) cntb[abs(2 * k - n - 1)]++;
  ll ans = 1;
  for (auto [p, q] : cntb)
  {
    ll x = q, y = cnta[p];
    if (y > x)
    {
      cout << 0 << endl;
      return 0;
    }
    if (x == 1)
    {
      if (y != 1)
      {
        cout << 0 << endl;
        return 0;
      }
    }
    else if (y == 1 or y == 2)
      ans = ans * 2 % mod;
  }
  for (auto [p, _] : cnta)
  {
    if (!cntb.count(p))
    {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}