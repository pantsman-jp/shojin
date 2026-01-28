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
  int n, m;
  cin >> n >> m;
  vector<ll> l(n);
  rep(i, 0, n) cin >> l[i], ++l[i];
  ll left = *max_element(all(l)) - 1, right = accumulate(all(l), 0LL);
  while (left + 1 < right)
  {
    ll mid = (left + right) / 2;
    ll row = 1, len = 0;
    rep(i, 0, n)
    {
      len += l[i];
      if (len > mid)
        row++, len = l[i];
    }
    if (row > m)
      left = mid;
    else
      right = mid;
  }
  cout << right - 1 << endl;
}