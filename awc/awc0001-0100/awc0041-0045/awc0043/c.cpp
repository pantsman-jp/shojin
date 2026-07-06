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
  int n;
  cin >> n;
  vector<vector<int>> buka(n);
  rep(i, 1, n) {
    int p;
    cin >> p;
    buka[p - 1].emplace_back(i);
  }
  vector<ll> w(n);
  rep(i, 0, n) cin >> w[i];
  vector<ll> s(n);
  ll ans = 0;
  rrep(i, 0, n) {
    s[i] += w[i];
    if (buka[i].size() >= 1) {
      ll max_s = -1;
      ll min_s = -1;
      for (int child : buka[i]) {
        s[i] += s[child];
        if (max_s == -1 or s[child] > max_s) max_s = s[child];
        if (min_s == -1 or s[child] < min_s) min_s = s[child];
      }
      if (buka[i].size() >= 2) chmax(ans, max_s - min_s);
    }
  }
  cout << ans << '\n';
  return 0;
}