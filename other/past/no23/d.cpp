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
  int h, w;
  char c1, c2;
  cin >> h >> w >> c1 >> c2;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  map<char, vector<pii>> pos;
  rep(i, 0, h) rep(j, 0, w) {
    if (s[i][j] == c1) pos[c1].emplace_back(i, j);
    if (s[i][j] == c2) pos[c2].emplace_back(i, j);
  }
  for (auto [i1, j1] : pos[c1]) {
    for (auto [i2, j2] : pos[c2]) {
      if (abs(i1 - i2) + abs(j1 - j2) == 1) {
        yn(true);
        return 0;
      }
    }
  }
  yn(false);
  return 0;
}