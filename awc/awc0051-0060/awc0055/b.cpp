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

vector<pll> post;

int solve(int pq) {
  ll mn = INF, idx = -1;
  rep(i, 0, post.size()) {
    auto [x, c] = post[i];
    ll dist = abs(x - pq);
    if (dist < mn) {
      mn = dist;
      idx = i;
    } else if (dist == mn) {
      if (idx == -1 or post[i].first < post[idx].first) {
        idx = i;
      }
    }
  }
  return idx;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, p, q;
  cin >> n >> p >> q;
  post.resize(n);
  rep(i, 0, n) cin >> post[i].first >> post[i].second;
  sort(all(post));
  int p_idx = solve(p);
  int q_idx = solve(q);
  ll ans = 0;
  if (p_idx == q_idx) {
    ans = post[p_idx].second + 2;
  } else {
    ans = (post[p_idx].second + 1) + (post[q_idx].second + 1);
  }
  cout << ans << '\n';
  return 0;
}