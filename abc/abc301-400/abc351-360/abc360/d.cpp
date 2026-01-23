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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll t;
  string s;
  cin >> n >> t >> s;
  vector<ll> xp, xn;
  rep(i, 0, n)
  {
    ll x;
    cin >> x;
    if (s[i] == '1')
      xp.push_back(x);
    else
      xn.push_back(x);
  }
  sort(all(xp)), sort(all(xn));
  ll l = 0, r = 0, ans = 0;
  int m = xn.size();
  for (ll x : xp)
  {
    while (l < m and xn[l] < x)
      l++;
    while (r < m and xn[r] <= x + 2 * t)
      r++;
    ans += r - l;
  }
  cout << ans << endl;
}