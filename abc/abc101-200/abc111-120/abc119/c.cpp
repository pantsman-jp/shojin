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

int n, a, b, c;
vector<int> l;

int dfs(int i, int x, int y, int z) {
  if (i == n) {
    if (x == 0 or y == 0 or z == 0) return inf;
    return abs(x - a) + abs(y - b) + abs(z - c);
  }
  int res = dfs(i + 1, x, y, z);
  chmin(res, dfs(i + 1, x + l[i], y, z) + (x != 0 ? 10 : 0));
  chmin(res, dfs(i + 1, x, y + l[i], z) + (y != 0 ? 10 : 0));
  chmin(res, dfs(i + 1, x, y, z + l[i]) + (z != 0 ? 10 : 0));
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> a >> b >> c;
  l.resize(n);
  rep(i, 0, n) cin >> l[i];
  cout << dfs(0, 0, 0, 0) << '\n';
  return 0;
}