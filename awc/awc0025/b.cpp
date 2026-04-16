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

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w, n;
  cin >> h >> w >> n;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  string t;
  cin >> t;
  int r = 0, c = 0;
  vector seen(h, vector<bool>(w));
  seen[r][c] = true;
  for (char op : t) {
    int nr = r, nc = c;
    if (op == 'U')
      nr--;
    else if (op == 'D')
      nr++;
    else if (op == 'L')
      nc--;
    else if (op == 'R')
      nc++;
    if (!out(nr, nc, h, w)) r = nr, c = nc;
    seen[r][c] = true;
  }
  int ans = 0;
  rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#' and !seen[i][j]) ans++;
  cout << ans << '\n';
  return 0;
}