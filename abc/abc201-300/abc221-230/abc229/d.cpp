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
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  vector<int> dot(n + 1);
  rep(i, 0, n) dot[i + 1] = dot[i] + (s[i] == '.' ? 1 : 0);
  int ans = 0, r = 0;
  rep(l, 0, n) {
    while (r <= n - 1 and dot[r + 1] - dot[l] <= k) r++;
    chmax(ans, r - l);
  }
  cout << ans << endl;
  return 0;
}