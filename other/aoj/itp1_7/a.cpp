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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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
  while (true) {
    int m, f, r;
    cin >> m >> f >> r;
    if (m == -1 and f == -1 and r == -1) break;
    if (m == -1 or f == -1) {
      cout << "F\n";
    } else if (m + f >= 80) {
      cout << "A\n";
    } else if (m + f >= 65) {
      cout << "B\n";
    } else if (m + f >= 50) {
      cout << "C\n";
    } else if (m + f >= 30) {
      if (r >= 50) {
        cout << "C\n";
      } else {
        cout << "D\n";
      }
    } else {
      cout << "F\n";
    }
  }
  return 0;
}