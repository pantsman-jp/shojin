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
  int n, m;
  cin >> n >> m;
  queue<int> q;
  vector<queue<int>> a(m);
  vector<vector<int>> mem(n);
  rep(i, 0, m) {
    int k;
    cin >> k;
    rep(_, 0, k) {
      int aij;
      cin >> aij;
      a[i].push(aij - 1);
    }
    mem[a[i].front()].push_back(i);
  }
  rep(i, 0, n) if (mem[i].size() == 2) q.push(i);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (auto p : mem[now]) {
      a[p].pop();
      if (!a[p].empty()) {
        mem[a[p].front()].push_back(p);
        if (mem[a[p].front()].size() == 2) q.push(a[p].front());
      }
    }
  }
  bool ok = true;
  for (auto p : a)
    if (!p.empty()) ok = false;
  yn(ok);
  return 0;
}