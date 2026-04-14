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
  vector is(26, vector<int>(n + 2, n + 1));
  rep(i, 0, n) is[s[i] - 'a'][i] = i + 1;
  rep(c, 0, 26) rrep(i, 0, n + 1) chmin(is[c][i], is[c][i + 1]);
  ll ans = 0;
  rep(l, 0, n) {
    int r = l;
    for (char c : t) r = is[c - 'a'][r];
    ans += r - l - 1;
  }
  cout << ans << '\n';
  return 0;
}