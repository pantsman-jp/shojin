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
  int n;
  ll s;
  cin >> n >> s;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  int front = n / 2;
  int back = n - front;
  vector<ll> left, right;
  rep(bit, 0, 1 << front) {
    ll sum = 0;
    rep(i, 0, front) if ((bit & (1 << i)) != 0) sum += a[i];
    left.push_back(sum);
  }
  rep(bit, 0, 1 << back) {
    ll sum = 0;
    rep(i, 0, back) if ((bit & (1 << i)) != 0) sum += a[front + i];
    right.push_back(sum);
  }
  sort(all(right));
  ll ans = 0;
  for (ll x : left) {
    auto [l, r] = equal_range(all(right), s - x);
    ans += r - l;
  }
  cout << ans << endl;
  return 0;
}