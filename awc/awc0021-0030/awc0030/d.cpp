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
  int n;
  cin >> n;
  vector<int> t(n), deg(n);
  rep(i, 0, n) {
    cin >> t[i];
    t[i]--;
    deg[t[i]]++;
  }
  queue<int> q;
  rep(i, 0, n) if (deg[i] == 0) q.push(i);
  vector<bool> is_cycle(n, true);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    is_cycle[v] = false;
    deg[t[v]]--;
    if (deg[t[v]] == 0) q.push(t[v]);
  }
  vector<int> cycle_len(n, 0);
  rep(i, 0, n) {
    if (is_cycle[i] and cycle_len[i] == 0) {
      vector<int> v;
      int curr = i;
      while (cycle_len[curr] == 0) {
        cycle_len[curr] = -1;
        v.push_back(curr);
        curr = t[curr];
      }
      int sz = v.size();
      for (int v : v) cycle_len[v] = sz;
    }
  }
  vector<int> ans(n, 0);
  auto get_len = [&](auto self, int v) -> int {
    if (cycle_len[v] > 0) return cycle_len[v];
    if (ans[v] > 0) return ans[v];
    return ans[v] = self(self, t[v]);
  };
  rep(i, 0, n) cout << get_len(get_len, i) << " ";
  cout << '\n';
  return 0;
}