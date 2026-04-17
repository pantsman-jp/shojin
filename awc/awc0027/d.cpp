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
  vector<pii> hs(n);
  rep(i, 0, n) cin >> hs[i].first >> hs[i].second;
  sort(all(hs));
  vector<int> p(m);
  rep(i, 0, m) cin >> p[i];
  sort(all(p));
  int pos = 0;
  priority_queue<int> q;
  long long ans = 0;
  rep(i, 0, m) {
    while (pos < n and hs[pos].first <= p[i]) {
      q.push(hs[pos].second);
      pos++;
    }
    if (q.size()) {
      ans += q.top();
      q.pop();
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}