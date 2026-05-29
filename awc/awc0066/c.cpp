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
  int n, q;
  cin >> n >> q;
  vector<ll> w(n);
  rep(i, 0, n) cin >> w[i];
  vector<ll> s(n + 1);
  rep(_, 0, q) {
    int l, r;
    ll d;
    cin >> l >> r >> d;
    l--, r--;
    s[l] += d, s[r + 1] -= d;
  }
  rep(i, 0, n) s[i + 1] += s[i];
  int ans = 0;
  rep(i, 0, n) {
    w[i] = max(w[i] - s[i], 0ll);
    if (w[i] == 0) ans++;
  }
  cout << ans << '\n';
  return 0;
}