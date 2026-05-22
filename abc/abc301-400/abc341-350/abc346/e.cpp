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
  int h, w, m;
  cin >> h >> w >> m;
  vector<int> t(m), a(m), x(m);
  rep(i, 0, m) cin >> t[i] >> a[i] >> x[i];
  int rh = h, rw = w;
  map<int, ll> cnt;
  vector<bool> usedh(h), usedw(w);
  for (int i = m - 1; i >= 0; i--) {
    a[i]--;
    if (t[i] == 1) {
      if (usedh[a[i]]) continue;
      usedh[a[i]] = true;
      cnt[x[i]] += rw;
      rh--;
    } else {
      if (usedw[a[i]]) continue;
      usedw[a[i]] = true;
      cnt[x[i]] += rh;
      rw--;
    }
  }
  cnt[0] += (ll)rh * rw;
  vector<pair<int, ll>> ans;
  for (auto p : cnt)
    if (p.second != 0) ans.emplace_back(p);
  cout << ans.size() << endl;
  for (auto [c, x] : ans) cout << c << ' ' << x << '\n';
  return 0;
}