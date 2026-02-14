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
#define yn(tf) cout << (tf ? "Yes\n" : "No\n");
#define dout(x) cout << fixed << setprecision(10) << x << "\n";
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
using mint = modint1000000007;

mint modncr(ll n, ll r) {
  if (r < 0 or r > n) return 0;
  if (r > n - r) r = n - r;
  mint num = 1, den = 1;
  rep(i, 0, r) num *= (n - i), den *= (i + 1);
  return num / den;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll x, y;
  cin >> x >> y;
  if ((-x + 2 * y) % 3 != 0 or (2 * x - y) % 3 != 0)
    cout << 0 << endl;
  else {
    ll n = (-x + 2 * y) / 3, m = (2 * x - y) / 3;
    cout << modncr(n + m, n).val() << endl;
  }
  return 0;
}