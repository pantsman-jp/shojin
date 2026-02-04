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
  int n, q;
  cin >> n >> q;
  vector<int> front(n + 1, -1), back(n + 1, -1);
  rep(_, 0, q) {
    int t, x, y;
    cin >> t;
    if (t == 1) {
      cin >> x >> y;
      front[y] = x;
      back[x] = y;
    } else if (t == 2) {
      cin >> x >> y;
      front[y] = -1;
      back[x] = -1;
    } else {
      cin >> x;
      while (front[x] != -1) x = front[x];
      vector<int> ans;
      while (x != -1) {
        ans.push_back(x);
        x = back[x];
      }
      cout << ans.size() << " ";
      for (int a : ans) cout << a << " ";
      cout << endl;
    }
  }
  return 0;
}