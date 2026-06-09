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

const vector<int> di = {0, 1};
const vector<int> dj = {1, 0};

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, 0, h) cin >> a[i];
  vector dp(h, vector<mint>(w, mint{0}));
  dp[0][0] = 1;
  rep(i, 0, h) rep(j, 0, w) rep(d, 0, 2) {
    int ni = i + di[d], nj = j + dj[d];
    if (out(ni, nj, h, w) or a[ni][nj] == '#') continue;
    dp[ni][nj] += dp[i][j];
  }
  cout << dp[h - 1][w - 1].val() << endl;
  return 0;
}