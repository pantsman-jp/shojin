#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, k;
  cin >> n >> m >> k;
  ll p = lcm(n, m);
  auto f = [&](ll x)
  {
    ll c = x / n + x / m - 2 * (x / p);
    return c >= k;
  };
  ll l = 0, r = INF;
  while (l < r)
  {
    ll mid = l + (r - l) / 2;
    if (f(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << r << endl;
}