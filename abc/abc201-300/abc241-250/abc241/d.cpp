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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  multiset<ll> a;
  rep(_, 0, q) {
    int t, k;
    ll x;
    bool ok = true;
    cin >> t;
    if (t == 1) {
      cin >> x;
      a.insert(x);
    } else if (t == 2) {
      cin >> x >> k;
      auto it = a.upper_bound(x);
      rep(_, 0, k) {
        if (it == a.begin())
          ok = false;
        else
          it--;
      }
      if (ok)
        cout << *it << endl;
      else
        cout << -1 << endl;
    } else {
      cin >> x >> k;
      auto it = a.lower_bound(x);
      rep(_, 0, k - 1) {
        if (it == a.end())
          ok = false;
        else
          it++;
      }
      if (ok and it != a.end())
        cout << *it << endl;
      else
        cout << -1 << endl;
    }
  }
  return 0;
}