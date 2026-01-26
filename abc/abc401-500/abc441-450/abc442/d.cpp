#include <bits/stdc++.h>
#include <atcoder/segtree>
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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<int> sum(n + 1);
  rep(i, 0, n) sum[i + 1] = sum[i] + a[i];
  rep(_, 0, q)
  {
    int t, x, l, r;
    cin >> t;
    if (t == 1)
    {
      cin >> x;
      sum[x] += a[x] - a[x - 1];
      swap(a[x - 1], a[x]);
    }
    if (t == 2)
    {
      cin >> l >> r;
      cout << sum[r] - sum[l - 1] << endl;
    }
  }
}