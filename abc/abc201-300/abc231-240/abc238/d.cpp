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

map<pll, bool> mp;

bool f(ll a, ll s) {
  if (s == 0) return a == 0;
  auto p = make_pair(a, s);
  if (mp.count(p) != 0) return mp[p];
  rep(x, 0, 2) rep(y, 0, 2) {
    if ((x & y) != (a & 1) or s - x - y < 0 or (s - x - y) % 2 != 0) continue;
    if (f(a >> 1, (s - x - y) >> 1)) return mp[p] = true;
  }
  return mp[p] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) {
    ll a, s;
    cin >> a >> s;
    mp = map<pll, bool>();
    yn(f(a, s));
  }
  return 0;
}