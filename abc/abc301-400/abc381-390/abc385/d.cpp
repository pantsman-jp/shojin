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
  int n, m;
  ll sx, sy;
  cin >> n >> m >> sx >> sy;
  map<ll, set<ll>> xs, ys;
  rep(i, 0, n)
  {
    int x, y;
    cin >> x >> y;
    xs[y].insert(x);
    ys[x].insert(y);
  }
  int ans = 0;
  auto f = [&](map<ll, set<ll>> &xs, map<ll, set<ll>> &ys, ll y, ll l, ll r)
  {
    if (l > r)
      swap(l, r);
    auto &st = xs[y];
    while (true)
    {
      auto it = st.lower_bound(l);
      if (it == st.end())
        break;
      if (*it > r)
        break;
      ys[*it].erase(y);
      st.erase(it);
      ans++;
    }
  };
  rep(_, 0, m)
  {
    char d;
    ll c;
    cin >> d >> c;
    ll nx = sx, ny = sy;
    if (d == 'U')
      ny += c;
    if (d == 'D')
      ny -= c;
    if (d == 'R')
      nx += c;
    if (d == 'L')
      nx -= c;
    if (sy == ny)
      f(xs, ys, sy, sx, nx);
    else
      f(ys, xs, sx, sy, ny);
    sx = nx;
    sy = ny;
  }
  cout << sx << ' ' << sy << ' ' << ans << endl;
}