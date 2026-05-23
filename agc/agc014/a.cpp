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
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define dout(x) cout << fixed << setprecision(10) << x << "\n"
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b and b == c and a % 2 == 0) {
    cout << -1 << '\n';
  } else if (a % 2 == 1 or b % 2 == 1 or c % 2 == 1) {
    cout << 0 << '\n';
  } else {
    int ans = 0;
    while (a % 2 == 0 and b % 2 == 0 and c % 2 == 0) {
      ans++;
      int x = a, y = b, z = c;
      a = (y + z) / 2;
      b = (x + z) / 2;
      c = (x + y) / 2;
    }
    cout << ans << '\n';
  }
  return 0;
}