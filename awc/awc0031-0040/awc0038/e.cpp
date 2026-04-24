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
  ll m;
  cin >> n >> m >> k;
  vector<ll> p(n);
  rep(i, 0, n) cin >> p[i];
  vector<ll> g(n);
  rep(i, 0, k) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u] |= 1LL << v;
    g[v] |= 1LL << u;
  }
  rep(i, 0, n) g[i] |= 1LL << i;
  int n1 = n / 2;
  int n2 = n - n1;
  int mask = (1 << n1) - 1;
  vector<ll> memo(1 << n1);
  for (int s = 1; s < (1 << n1); s++) {
    int i = 31 - __builtin_clz(s);
    memo[s] = max(memo[s ^ (1 << i)], memo[s & ~g[i] & mask] + p[i]);
  }
  ll ans = *max_element(memo.begin(), memo.end());
  vector<ll> memo2(1 << n2), ng(1 << n2);
  rep(s, 1, 1 << n2) {
    int i = 31 - __builtin_clz(s);
    memo2[s] =
        max(memo2[s ^ (1 << i)], memo2[s & ~(g[i + n1] >> n1)] + p[i + n1]);
    ng[s] = ng[s ^ (1 << i)] | g[i + n1];
    ans = max(ans, memo2[s] + memo[~ng[s] & mask]);
  }
  cout << min(m, ans) << endl;
  return 0;
}