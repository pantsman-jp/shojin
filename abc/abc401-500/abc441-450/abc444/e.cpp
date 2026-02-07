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
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  multiset<int> s;
  ll ans = 0;
  int l = 0;
  rep(r, 0, n) {
    s.insert(a[r]);
    while (true) {
      auto it = s.find(a[r]);
      bool ok = false;
      if (it != s.begin() and a[r] - *prev(it) < d) ok = true;
      auto nxt = next(it);
      if (nxt != s.end() and *nxt - a[r] < d) ok = true;
      if (!ok) break;
      s.erase(s.find(a[l]));
      l++;
    }
    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}