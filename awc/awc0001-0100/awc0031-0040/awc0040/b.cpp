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
  int m;
  ll s;
  cin >> m >> s;
  vector<ll> b(m);
  rep(i, 0, m) cin >> b[i];
  ll q = s / m, r = s % m;
  rep(i, 0, m) {
    if (i < r)
      b[i] += q + 1;
    else
      b[i] += q;
  }
  vector<ll> sum(m + 1);
  rep(i, 0, m) sum[i + 1] = sum[i] + b[i];
  int n;
  cin >> n;
  rep(_, 0, n) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << sum[r + 1] - sum[l] << '\n';
  }
  return 0;
}