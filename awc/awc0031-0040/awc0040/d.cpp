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
  ll n, g, f;
  cin >> n >> g >> f;
  vector<pll> pr(n);
  rep(i, 0, n) cin >> pr[i].first >> pr[i].second;
  pr.emplace_back(0, 0);
  pr.emplace_back(g, 0);
  sort(all(pr));
  priority_queue<ll> q;
  ll ans = 0;
  rep(i, 1, n + 2) {
    ll trip = pr[i].first - pr[i - 1].first;
    f -= trip;
    while (!q.empty() and f < 0) {
      ans++;
      f += q.top();
      q.pop();
    }
    if (f < 0) {
      cout << -1 << '\n';
      return 0;
    }
    q.push(pr[i].second);
  }
  cout << ans << '\n';
  return 0;
}