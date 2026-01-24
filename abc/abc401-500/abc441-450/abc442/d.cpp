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

ll op(ll a, ll b)
{
  return a + b;
}

ll e()
{
  return 0;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  segtree<ll, op, e> seg(a);
  rep(_, 0, q)
  {
    int t;
    cin >> t;
    if (t == 1)
    {
      int x;
      cin >> x;
      x--;
      ll v1 = seg.get(x), v2 = seg.get(x + 1);
      seg.set(x, v2), seg.set(x + 1, v1);
    }
    else
    {
      int l, r;
      cin >> l >> r;
      l--;
      cout << seg.prod(l, r) << endl;
    }
  }
}