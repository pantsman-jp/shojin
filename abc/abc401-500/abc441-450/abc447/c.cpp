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
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int i = 0, j = 0;
  ll ans = 0;
  while (true) {
    ll cnts = 0, cntt = 0;
    while (i < n and s[i] == 'A') cnts++, i++;
    while (j < m and t[j] == 'A') cntt++, j++;
    ans += abs(cnts - cntt);
    if (i == n and j == m) break;
    if (i == n or j == m or s[i] != t[j]) {
      cout << -1 << '\n';
      return 0;
    }
    i++, j++;
  }
  cout << ans << '\n';
  return 0;
}