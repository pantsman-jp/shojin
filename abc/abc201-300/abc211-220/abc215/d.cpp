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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<bool> ok(m + 1, true);
  rep(i, 0, n) {
    int a;
    cin >> a;
    for (int p = 2; p * p <= a; p++) {
      if (a % p != 0) continue;
      ok[p] = false;
      while (a % p == 0) a /= p;
    }
    if (1 < a and a <= m) ok[a] = false;
  }
  rep(i, 2, m + 1) {
    if (ok[i]) continue;
    for (int k = i; k <= m; k += i) ok[k] = false;
  }
  set<int> ans;
  rep(i, 1, m + 1) if (ok[i]) ans.insert(i);
  cout << ans.size() << endl;
  for (int x : ans) cout << x << endl;
  return 0;
}