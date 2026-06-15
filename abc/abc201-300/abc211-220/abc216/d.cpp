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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m), pos(n);
  rep(i, 0, m) {
    int k;
    cin >> k;
    a[i] = vector<int>(k);
    rep(j, 0, k) cin >> a[i][j];
    rep(j, 0, k) {
      a[i][j]--;
      pos[a[i][j]].push_back(i);
    }
  }
  vector<int> cnt(n);
  queue<int> q;
  rep(i, 0, m) {
    int t = a[i].back();
    cnt[t]++;
  }
  rep(i, 0, n) if (cnt[i] == 2) q.push(i);
  int take = 0;
  while (q.size()) {
    int x = q.front();
    q.pop();
    take++;
    rep(i, 0, 2) {
      int p = pos[x][i];
      a[p].pop_back();
      if (a[p].size()) {
        int t = a[p].back();
        cnt[t]++;
        if (cnt[t] == 2) q.push(t);
      }
    }
  }
  yn(take == n);
  return 0;
}