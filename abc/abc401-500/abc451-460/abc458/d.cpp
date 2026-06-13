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
  int x, q;
  cin >> x >> q;
  priority_queue<int> l;
  priority_queue<int, vector<int>, greater<int>> r;
  rep(_, 0, q) {
    rep(__, 0, 2) {
      int a;
      cin >> a;
      if (a < x)
        l.push(a);
      else
        r.push(a);
    }
    while (l.size() > r.size()) {
      r.push(x);
      x = l.top();
      l.pop();
    }
    while (r.size() > l.size()) {
      l.push(x);
      x = r.top();
      r.pop();
    }
    cout << x << '\n';
  }
  return 0;
}