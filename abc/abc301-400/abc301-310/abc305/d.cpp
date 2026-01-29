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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  cin >> q;
  vector<int> sum(n);
  rep(i, 1, n)
  {
    sum[i] = sum[i - 1];
    if (i % 2 == 0)
      sum[i] += a[i] - a[i - 1];
  }
  auto f = [&](int x)
  {
    int i = lower_bound(all(a), x) - a.begin() - 1;
    if (i < 0)
      return 0;
    int ans = sum[i];
    if (i % 2 == 1)
      ans += x - a[i];
    return ans;
  };
  rep(_, 0, q)
  {
    int l, r;
    cin >> l >> r;
    cout << f(r) - f(l) << endl;
  }
}