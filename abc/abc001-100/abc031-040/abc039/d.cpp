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

const vector<int> di = {-1, -1, 0, 1, 1, 1, 0, -1};
const vector<int> dj = {0, 1, 1, 1, 0, -1, -1, -1};

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  vector<string> t(h, string(w, '.'));
  rep(i, 0, h) rep(j, 0, w) {
    bool ok = (s[i][j] == '#');
    rep(d, 0, 8) {
      int ni = i + di[d], nj = j + dj[d];
      if (!out(ni, nj, h, w) and s[ni][nj] == '.') ok = false;
    }
    if (ok) t[i][j] = '#';
  }
  vector<string> s2(h, string(w, '.'));
  rep(i, 0, h) rep(j, 0, w) {
    if (t[i][j] == '#') s2[i][j] = '#';
    rep(d, 0, 8) {
      int ni = i + di[d], nj = j + dj[d];
      if (!out(ni, nj, h, w) and t[ni][nj] == '#') s2[i][j] = '#';
    }
  }
  if (s == s2) {
    cout << "possible" << endl;
    rep(i, 0, h) cout << t[i] << endl;
  } else {
    cout << "impossible" << endl;
  }
  return 0;
}