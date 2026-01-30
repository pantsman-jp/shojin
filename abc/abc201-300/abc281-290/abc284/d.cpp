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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) {
    ll n;
    cin >> n;
    for (ll m = 2; m * m * m <= n; m++) {
      ll p2 = m * m;
      if (n % p2 == 0) {
        cout << m << " " << n / p2 << endl;
        break;
      } else if (n % m == 0) {
        cout << (ll)sqrt(n / m) << " " << m << endl;
        break;
      }
    }
  }
  return 0;
}