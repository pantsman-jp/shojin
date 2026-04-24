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
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll mx = 0, sum = 0;
  rep(i, 0, n) {
    cin >> a[i];
    chmax(mx, a[i]);
    sum += a[i];
  }
  auto check = [&](ll x) {
    ll cnt = 0, now = 0;
    rep(i, 0, n) {
      if (now + a[i] > x) {
        cnt++;
        now = a[i];
      } else
        now += a[i];
    }
    return cnt <= k;
  };
  ll l = mx - 1, r = sum;
  while (r - l > 1) {
    ll mid = l + (r - l) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << r << '\n';
  return 0;
}