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
  int n, q;
  cin >> n >> q;
  vector<ll> r(n);
  rep(i, 0, n) cin >> r[i];
  sort(all(r));
  vector<ll> sum(n + 1);
  rep(i, 0, n) sum[i + 1] = sum[i] + r[i];
  rep(_, 0, q)
  {
    ll x;
    cin >> x;
    cout << upper_bound(all(sum), x) - sum.begin() - 1 << endl;
  }
}