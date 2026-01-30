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
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using P = pair<int, int>;
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
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  dsu uf(n);
  rep(i, 0, n) {
    int j = (i + 1) % n;
    if (a[i] == a[j] or (a[i] + 1) % m == a[j]) uf.merge(i, j);
  }
  vector<ll> s(n);
  rep(i, 0, n) s[uf.leader(i)] += a[i];
  ll mx = 0;
  rep(i, 0, n) chmax(mx, s[i]);
  cout << accumulate(all(a), 0ll) - mx << endl;
}