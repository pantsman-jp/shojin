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
  cin >> n >> q;
  vector<int> up(n, -1), down(n, -1), bottom(n);
  rep(i, 0, n) bottom[i] = i;
  rep(i, 0, q) {
    int c, p;
    cin >> c >> p;
    c--, p--;
    int b = down[c];
    if (b != -1) up[b] = -1;
    up[p] = c;
    down[c] = p;
  }
  vector<int> ans(n);
  rep(i, 0, n) {
    int card = bottom[i];
    if (down[card] != -1) continue;
    int cnt = 0;
    while (card != -1) {
      cnt++;
      card = up[card];
    }
    ans[i] = cnt;
  }
  rep(i, 0, n) cout << ans[i] << " ";
  cout << '\n';
  return 0;
}