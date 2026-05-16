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
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  rep(i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % n) {
    cout << -1 << '\n';
    return 0;
  }
  sum /= n;
  ll ans = 0, pos = 0, cnt = 0;
  rep(i, 0, n) {
    while (a[i] > 0) {
      ll del = min(a[i], sum - cnt);
      a[i] -= del;
      cnt += del;
      ans += abs(pos - i) * del;
      if (cnt == sum) {
        pos++;
        cnt = 0;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}