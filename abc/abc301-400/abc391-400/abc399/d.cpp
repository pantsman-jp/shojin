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

void solve()
{
  int n;
  cin >> n;
  vector<int> a(2 * n);
  rep(i, 0, 2 * n) cin >> a[i], a[i]--;
  vector<vector<int>> pos(n);
  rep(i, 0, 2 * n) pos[a[i]].push_back(i);
  set<P> cand;
  rep(i, 0, 2 * n - 1)
  {
    int x = a[i], y = a[i + 1];
    if (x > y)
      swap(x, y);
    if (x == y)
      continue;
    cand.emplace(x, y);
  }
  int ans = 0;
  for (auto [x, y] : cand)
  {
    int xl = pos[x][0], xr = pos[x][1];
    int yl = pos[y][0], yr = pos[y][1];
    if (xl + 1 == xr or yl + 1 == yr)
      continue;
    if (abs(xl - yl) == 1 and abs(xr - yr) == 1)
      ans++;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) solve();
}