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
  int n, a, b;
  cin >> n >> a >> b;
  vector tkh(n + 1, vector<int>(n + 1)), aok(n + 1, vector<int>(n + 1));
  rep(_, 0, a) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    tkh[r1][c1]++, tkh[r1][c2 + 1]--;
    tkh[r2 + 1][c1]--, tkh[r2 + 1][c2 + 1]++;
  }
  rep(_, 0, b) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    aok[r1][c1]++, aok[r1][c2 + 1]--;
    aok[r2 + 1][c1]--, aok[r2 + 1][c2 + 1]++;
  }
  rep(i, 0, n) rep(j, 0, n) {
    tkh[i][j + 1] += tkh[i][j];
    aok[i][j + 1] += aok[i][j];
  }
  rep(j, 0, n) rep(i, 0, n) {
    tkh[i + 1][j] += tkh[i][j];
    aok[i + 1][j] += aok[i][j];
  }
  int ans = 0;
  rep(i, 0, n) rep(j, 0, n) if (tkh[i][j] > 0 and aok[i][j] > 0) ans++;
  cout << ans << endl;
  return 0;
}