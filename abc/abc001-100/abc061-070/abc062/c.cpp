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

ll solve(ll h, ll w) {
  ll ans = INF;
  rep(i, 1, h) {
    ll s1 = i * w;
    {
      ll s2_h = ((h - i) / 2) * w;
      ll s3_h = (h - i - (h - i) / 2) * w;
      chmin(ans, max({s1, s2_h, s3_h}) - min({s1, s2_h, s3_h}));
    }
    {
      ll s2_w = (h - i) * (w / 2);
      ll s3_w = (h - i) * (w - w / 2);
      chmin(ans, max({s1, s2_w, s3_w}) - min({s1, s2_w, s3_w}));
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll h, w;
  cin >> h >> w;
  if (h % 3 == 0 or w % 3 == 0) {
    cout << 0 << '\n';
  } else {
    cout << min(solve(h, w), solve(w, h)) << '\n';
  }
  return 0;
}