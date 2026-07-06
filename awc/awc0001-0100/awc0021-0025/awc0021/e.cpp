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

using Mat = vector<vector<ll>>;

Mat mul(Mat A, Mat B) {
  Mat C(2, vector<ll>(2, -INF));
  rep(i, 0, 2) rep(k, 0, 2) rep(j, 0, 2) {
    if (A[i][k] != -INF and B[k][j] != -INF) {
      chmax(C[i][j], A[i][k] + B[k][j]);
    }
  }
  return C;
}

Mat matpow(Mat A, ll n) {
  Mat B(2, vector<ll>(2, -INF));
  B[0][0] = 0;
  B[1][1] = 0;
  while (n > 0) {
    if (n & 1) B = mul(B, A);
    A = mul(A, A);
    n >>= 1;
  }
  return B;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, a, b;
  cin >> n >> a >> b;
  if (n == 1) {
    cout << max(a, b) << '\n';
    return 0;
  }
  Mat xss(2, vector<ll>(2));
  xss[0][0] = b;
  xss[0][1] = b / 2;
  xss[1][0] = a;
  xss[1][1] = a / 2;
  Mat Xn = matpow(xss, n - 1);
  ll ans = -INF;
  chmax(ans, Xn[0][0] + b);
  chmax(ans, Xn[0][1] + a);
  chmax(ans, Xn[1][0] + b);
  chmax(ans, Xn[1][1] + a);
  cout << ans << '\n';
  return 0;
}