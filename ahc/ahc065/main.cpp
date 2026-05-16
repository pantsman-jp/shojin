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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n = 20;
  vector<vector<int>> a(n, vector<int>(n));
  rep(i, 0, n) {
    rep(j, 0, n) { cin >> a[i][j]; }
  }
  vector<vector<pii>> candidates(4);
  rep(j, 0, n) candidates[0].push_back({0, j});
  rep(i, 1, n) {
    if (i % 2 == 1)
      rrep(j, 1, n) candidates[0].push_back({i, j});
    else
      rep(j, 1, n) candidates[0].push_back({i, j});
  }
  rrep(i, 1, n) candidates[0].push_back({i, 0});
  rrep(j, 0, n) candidates[1].push_back({0, j});
  rep(i, 1, n) {
    if (i % 2 == 1)
      rep(j, 0, n - 1) candidates[1].push_back({i, j});
    else
      rrep(j, 0, n - 1) candidates[1].push_back({i, j});
  }
  rrep(i, 1, n) candidates[1].push_back({i, n - 1});
  rep(i, 0, n) candidates[2].push_back({i, 0});
  rep(j, 1, n) {
    if (j % 2 == 1)
      rrep(i, 1, n) candidates[2].push_back({i, j});
    else
      rep(i, 1, n) candidates[2].push_back({i, j});
  }
  rrep(j, 1, n) candidates[2].push_back({0, j});
  rep(i, 0, n) candidates[3].push_back({i, n - 1});
  rrep(j, 0, n - 1) {
    if ((n - 1 - j) % 2 == 1)
      rrep(i, 1, n) candidates[3].push_back({i, j});
    else
      rep(i, 1, n) candidates[3].push_back({i, j});
  }
  rep(j, 0, n - 1) candidates[3].push_back({0, j});
  vector<vector<pii>> all_candidates;
  rep(c_idx, 0, 4) {
    all_candidates.push_back(candidates[c_idx]);
    vector<pii> rev_path = candidates[c_idx];
    reverse(rev_path.begin(), rev_path.end());
    all_candidates.push_back(rev_path);
  }
  vector<pii> best_path;
  vector<int> best_ops;
  int min_ops = inf;
  rep(c_idx, 0, 8) {
    vector<pii> cur_path = all_candidates[c_idx];
    int l = cur_path.size();
    int out_idx = -1;
    vector<int> pos_init(n * n);
    rep(i, 0, l) {
      int r = cur_path[i].first;
      int c = cur_path[i].second;
      pos_init[a[r][c]] = i;
      if (r == 0 && c == n / 2) out_idx = i;
    }
    vector<int> cur_ops;
    int target = 0;
    int offset = 0;
    while (target < n * n) {
      int p = (pos_init[target] + offset) % l;
      int d1 = (out_idx - p + l) % l;
      int d2 = (p - out_idx + l) % l;
      if (d1 <= d2) {
        rep(k, 0, d1) cur_ops.push_back(1);
        offset = (offset + d1) % l;
      } else {
        rep(k, 0, d2) cur_ops.push_back(-1);
        offset = (offset - d2 + l) % l;
      }
      target++;
    }
    if ((int)cur_ops.size() < min_ops) {
      min_ops = cur_ops.size();
      best_path = cur_path;
      best_ops = cur_ops;
    }
  }
  cout << 1 << '\n';
  cout << best_path.size();
  rep(i, 0, (int)best_path.size()) cout << " " << best_path[i].first << " "
                                        << best_path[i].second;
  cout << '\n';
  cout << best_ops.size() << '\n';
  rep(i, 0, (int)best_ops.size()) cout << 0 << " " << best_ops[i] << '\n';
  return 0;
}