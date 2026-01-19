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
  ll n;
  cin >> n;
  for (ll d = 1; d * d * d < n; d++)
  {
    ll c = n - d * d * d;
    if (c % (3 * d) != 0)
      continue;
    c /= 3 * d;
    ll y = (sqrt(d * d + 4 * c) - d) / 2;
    if (y * y + d * y - c == 0)
    {
      cout << y + d << ' ' << y << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}