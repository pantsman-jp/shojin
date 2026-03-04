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
  int n, q;
  ll k;
  cin >> n >> k >> q;
  vector<ll> a(n + 1);
  rep(i, 1, n + 1) cin >> a[i];
  vector<ll> suma(n + 1);
  rep(i, 1, n + 1) suma[i] = suma[i - 1] + a[i];
  vector<ll> f(n + 1);
  rep(i, 1, n + 1) {
    int idx = upper_bound(all(suma), suma[i - 1] + k) - suma.begin();
    idx == n + 1 ? f[i] = n : f[i] = idx;
  }
  vector<ll> sumf(n + 1);
  rep(i, 1, n + 1) sumf[i] = sumf[i - 1] + f[i];
  rep(_, 0, q) {
    int l, r;
    cin >> l >> r;
    cout << sumf[r] - sumf[l - 1] << '\n';
  }
  return 0;
}