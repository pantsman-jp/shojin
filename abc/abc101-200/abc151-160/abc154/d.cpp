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
// using mint = modint1000000007;

ld sum(int n) { return n * (n + 1) / 2.0; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<ld> e(n);
  rep(i, 0, n) {
    int p;
    cin >> p;
    e[i] = sum(p) / (p * 1.0);
  }
  vector<ld> sum(n + 1);
  rep(i, 0, n) sum[i + 1] = sum[i] + e[i];
  ld ans = -1.0;
  rep(i, 0, n - k + 1) chmax(ans, sum[i + k] - sum[i]);
  dout(ans);
  return 0;
}