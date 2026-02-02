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

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<pii> dij;
  rep(di, -n, n) rep(dj, -n, n) {
    if (di * di + dj * dj == m) dij.push_back({di, dj});
  }
  vector dist(n, vector<int>(n, -1));
  queue<pii> q;
  q.push({0, 0});
  dist[0][0] = 0;
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (auto [di, dj] : dij) {
      int ni = i + di, nj = j + dj;
      if (out(ni, nj, n, n) or dist[ni][nj] != -1) continue;
      q.push({ni, nj});
      dist[ni][nj] = dist[i][j] + 1;
    }
  }
  rep(i, 0, n) {
    rep(j, 0, n) cout << dist[i][j] << " ";
    cout << endl;
  }
  return 0;
}