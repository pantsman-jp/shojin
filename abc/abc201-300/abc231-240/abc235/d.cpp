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
  ll a, n;
  cin >> a >> n;
  queue<ll> q;
  vector<int> dist(10 * n, -1);
  auto push = [&](ll nxt, ll now) -> void {
    if (nxt >= n * 10) return;
    if (dist[nxt] == -1) {
      q.push(nxt);
      dist[nxt] = dist[now] + 1;
    }
  };
  q.push(1);
  dist[1] = 0;
  while (!q.empty()) {
    ll x = q.front();
    q.pop();
    push(x * a, x);
    if (x % 10 != 0) {
      string sx = to_string(x);
      sx = sx.back() + sx.substr(0, sx.size() - 1);
      istringstream si(sx);
      ll y;
      si >> y;
      push(y, x);
    }
  }
  cout << dist[n] << endl;
  return 0;
}