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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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
  string s;
  cin >> n >> s;
  vector<int> v(n), f(n);
  rep(i, 0, n) {
    if (s[i] == 'V') v[i]++;
    if (s[i] == 'F') f[i]++;
    if (s[i] == 'B') v[i]++, f[i]++;
  }
  vector<int> sumv(n + 1), sumf(n + 1);
  rep(i, 0, n) {
    sumv[i + 1] = sumv[i] + v[i];
    sumf[i + 1] = sumf[i] + f[i];
  }
  ll ans = 0;
  map<int, int> cnt;
  cnt[0] = 1;
  rep(r, 0, n) {
    int diff = sumv[r + 1] - sumf[r + 1];
    ans += cnt[diff];
    cnt[diff]++;
  }
  cout << ans << '\n';
  return 0;
}