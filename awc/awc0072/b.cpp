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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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
  ll positive_sum = 0;
  vector<ll> negative_sum(n + 1);
  rep(i, 0, n) {
    ll a;
    cin >> a;
    if (a > 0) {
      positive_sum += a;
      negative_sum[i + 1] = negative_sum[i];
    } else {
      negative_sum[i + 1] = negative_sum[i] + a;
    }
  }
  ll mx_nega = -INF;
  rep(i, 0, n - k + 1) {
    chmax(mx_nega, negative_sum[i + k] - negative_sum[i]);
  }
  cout << positive_sum + mx_nega << '\n';
  return 0;
}