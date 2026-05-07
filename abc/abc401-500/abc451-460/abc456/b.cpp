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
  vector a(3, vector<int>(6));
  rep(i, 0, 3) rep(j, 0, 6) cin >> a[i][j];
  int cnt = 0;
  rep(i, 0, 6) rep(j, 0, 6) rep(k, 0, 6) {
    if ((a[0][i] == 4 && a[1][j] == 5 && a[2][k] == 6) ||
        (a[0][i] == 4 && a[1][j] == 6 && a[2][k] == 5) ||
        (a[0][i] == 5 && a[1][j] == 4 && a[2][k] == 6) ||
        (a[0][i] == 5 && a[1][j] == 6 && a[2][k] == 4) ||
        (a[0][i] == 6 && a[1][j] == 4 && a[2][k] == 5) ||
        (a[0][i] == 6 && a[1][j] == 5 && a[2][k] == 4)) {
      cnt++;
    }
  }
  dout(cnt / 216.0);
  return 0;
}