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
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, 0, n) cin >> h[i];
  deque<int> mx, mn;
  int ans = -inf;
  rep(r, 0, n) {
    while (!mx.empty() and h[mx.back()] <= h[r]) mx.pop_back();
    mx.push_back(r);
    while (!mn.empty() and h[mn.back()] >= h[r]) mn.pop_back();
    mn.push_back(r);
    if (mx.front() <= r - k) mx.pop_front();
    if (mn.front() <= r - k) mn.pop_front();
    if (r >= k - 1) chmax(ans, h[mx.front()] - h[mn.front()]);
  }
  cout << ans << endl;
  return 0;
}