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

vector<pair<ll, ll>> factorization(ll n) {
  vector<pair<ll, ll>> ans;
  for (ll p = 2; p * p <= n; p++) {
    if (n % p != 0) continue;
    ll e = 0;
    while (n % p == 0) n /= p, ++e;
    ans.push_back({p, e});
  }
  if (n != 1) ans.emplace_back(n, 1);
  return ans;
}

ll how_many(ll n, ll p) {
  ll ans = 0;
  while (n % p == 0) n /= p, ans++;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll k;
  cin >> k;
  ll ans = 0;
  for (auto [p, e] : factorization(k)) {
    ll f = 0;
    for (ll n = p;; n++) {
      f += how_many(n, p);
      if (f >= e) {
        chmax(ans, n);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}