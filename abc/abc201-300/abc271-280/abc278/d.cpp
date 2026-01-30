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
  map<int, ll> diff;
  int n, q;
  cin >> n;
  rep(i, 0, n) {
    ll a;
    cin >> a;
    diff[i] += a;
  }
  cin >> q;
  ll base = 0;
  rep(_, 0, q) {
    int t, i;
    ll x;
    cin >> t;
    if (t == 1) {
      cin >> x;
      base = x;
      diff.clear();
    } else if (t == 2) {
      cin >> i >> x;
      diff[i - 1] += x;
    } else {
      cin >> i;
      cout << base + diff[i - 1] << endl;
    }
  }
  return 0;
}