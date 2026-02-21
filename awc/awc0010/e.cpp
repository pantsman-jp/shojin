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
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, 0, n) p[i] = i;
  vector c(n, vector<ll>(n));
  rep(i, 0, n) rep(j, 0, n) cin >> c[i][j];
  ll ans = 0;
  do {
    int cnt = 0;
    vector<bool> seen(n);
    rep(i, 0, n) if (!seen[i]) {
      cnt++;
      int now = i;
      while (!seen[now]) {
        seen[now] = true;
        now = p[now];
      }
    }
    if (n - cnt <= k) {
      ll sum = 0;
      rep(i, 0, n) sum += c[p[i]][p[(i + 1) % n]];
      chmax(ans, sum);
    }
  } while (next_permutation(all(p)));
  cout << ans << endl;
  return 0;
}