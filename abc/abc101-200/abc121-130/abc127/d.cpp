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
  int n, m;
  cin >> n >> m;
  map<ll, ll> a, bc;
  rep(_, 0, n) {
    ll x;
    cin >> x;
    a[x]++;
  }
  rep(_, 0, m) {
    ll b, c;
    cin >> b >> c;
    bc[c] += b;
  }
  vector<pll> nums;
  for (auto [num, cnt] : a) nums.emplace_back(num, cnt);
  for (auto [num, cnt] : bc) nums.emplace_back(num, cnt);
  sort(rall(nums));
  ll ans = 0;
  for (auto [num, cnt] : nums) {
    if (n >= cnt) {
      ans += num * cnt;
      n -= cnt;
    } else {
      ans += num * n;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}