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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n), c(n);
  vector<vector<int>> t(n);
  rep(i, 0, n) {
    cin >> v[i] >> c[i];
    vector<int> ti(c[i]);
    rep(j, 0, c[i]) cin >> ti[j];
    t[i] = ti;
  }
  vector<pii> vi(n);
  rep(i, 0, n) vi[i] = {v[i], -i};
  sort(rall(vi));
  vector<int> count(m + 1);
  rep(p, 0, k) {
    int i = -vi[p].second;
    rep(j, 0, c[i]) count[t[i][j]]++;
  }
  int ans = 0;
  rep(i, 1, m + 1) if (count[i] == k) ans++;
  cout << ans << endl;
  return 0;
}