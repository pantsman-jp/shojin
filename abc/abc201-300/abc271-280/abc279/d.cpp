#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
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

ll a, b;

ld f(ll x) { return b * (ld)x + a / sqrt(1 + x); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> a >> b;
  ll l = 0, r = 1e18;
  while (l + 3 <= r) {
    ll x1 = (l * 2 + r) / 3;
    ll x2 = (l + r * 2) / 3;
    if (f(x1) < f(x2))
      r = x2;
    else
      l = x1;
  }
  dout(min({f(l), f(l + 1), f(r)}));
  return 0;
}