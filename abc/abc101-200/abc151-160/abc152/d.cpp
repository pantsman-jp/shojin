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
  cin >> n;
  vector cnt(10, vector<ll>(10));
  rep(i, 1, n + 1) {
    vector<int> d;
    int m = i;
    while (m > 0) d.push_back(m % 10), m /= 10;
    int a = d[0], b = d.back();
    if (a != 0 and b != 0) cnt[a][b]++;
  }
  ll ans = 0;
  rep(a, 1, 10) rep(b, 1, 10) ans += cnt[a][b] * cnt[b][a];
  cout << ans << endl;
  return 0;
}