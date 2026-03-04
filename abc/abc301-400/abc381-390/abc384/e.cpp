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

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w, x, p, q;
  cin >> h >> w >> x >> p >> q;
  p--, q--;
  vector<vector<ll>> s(h, vector<ll>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> s[i][j];
  ll ans = s[p][q];
  s[p][q] = 0;
  using tlii = tuple<ll, int, int>;
  priority_queue<tlii, vector<tlii>, greater<tlii>> pq;
  vector<vector<bool>> seen(h, vector<bool>(w));
  auto push = [&](int i, int j) {
    rep(d, 0, 4) {
      int ni = i + di[d], nj = j + dj[d];
      if (out(ni, nj, h, w) or seen[ni][nj]) continue;
      seen[ni][nj] = true;
      pq.emplace(s[ni][nj], ni, nj);
    }
  };
  push(p, q);
  while (!pq.empty()) {
    auto [ns, i, j] = pq.top();
    pq.pop();
    if (ns > (ans - 1) / x) break;
    ans += ns;
    push(i, j);
  }
  cout << ans << endl;
  return 0;
}