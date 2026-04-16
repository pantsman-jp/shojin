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
  int n, s;
  ll q;
  cin >> n >> s >> q;
  vector<pll> x(n);
  rep(i, 0, n) {
    cin >> x[i].first;
    x[i].second = i + 1;
  }
  sort(all(x));
  vector<int> nxt(n);
  rep(i, 0, n) {
    if (i == 0)
      nxt[i] = i + 1;
    else if (i == n - 1)
      nxt[i] = i - 1;
    else {
      ll dist_l = x[i].first - x[i - 1].first;
      ll dist_r = x[i + 1].first - x[i].first;
      if (dist_l < dist_r)
        nxt[i] = i - 1;
      else if (dist_r < dist_l)
        nxt[i] = i + 1;
      else if (x[i - 1].second < x[i + 1].second)
        nxt[i] = i - 1;
      else
        nxt[i] = i + 1;
    }
  }
  int start = -1;
  rep(i, 0, n) if (x[i].second == s) start = i;
  vector<int> path;
  vector<ll> visited(n, -1);
  int now = start;
  rep(step, 0, n + 1) {
    if (step == q) {
      cout << x[now].second << '\n';
      return 0;
    }
    if (visited[now] != -1) {
      ll loop_start = visited[now];
      ll rem = (q - loop_start) % (step - loop_start);
      cout << x[path[loop_start + rem]].second << '\n';
      return 0;
    }
    visited[now] = step;
    path.push_back(now);
    now = nxt[now];
  }
  return 0;
}