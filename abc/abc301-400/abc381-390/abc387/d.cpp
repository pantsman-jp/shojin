// Template: https://github.com/pantsman-jp/shojin/blob/main/abc/template
// License: CC0 1.0 Universal
// https://github.com/pantsman-jp/shojin/blob/main/LICENSE
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define YN(tf) cout << (tf ? "YES\n" : "NO\n")
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
template <typename T, typename U>
inline bool chmax(T& x, const U& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T, typename U>
inline bool chmin(T& x, const U& y) {
  if (x > y) {
    x = y;
    return true;
  }
  return false;
}
template <typename T>
inline T lcm(T a, T b) {
  return (a / std::gcd(a, b)) * b;
}
template <typename T>
inline T divceil(T a, T b) {
  return (a + b - 1) / b;
}
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using rpq = priority_queue<T, vector<T>, greater<T>>;
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

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  rep(i, 0, t) solve();
  return 0;
}

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

void solve() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  int si, sj, gi, gj;
  rep(i, 0, h) rep(j, 0, w) {
    if (s[i][j] == 'S') {
      si = i, sj = j;
    }
    if (s[i][j] == 'G') {
      gi = i, gj = j;
    }
  }
  queue<tuple<int, int, int>> q;
  vector dist(h, vector(w, vector<int>(4, inf)));
  rep(d, 0, 4) {
    q.emplace(si, sj, d);
    dist[si][sj][d] = 0;
  }
  while (!q.empty()) {
    auto [i, j, prev] = q.front();
    q.pop();
    rep(d, 0, 4) {
      if (prev % 2 == d % 2) continue;
      int ni = i + di[d], nj = j + dj[d];
      if (out(ni, nj, h, w) or s[ni][nj] == '#') continue;
      if (chmin(dist[ni][nj][d], dist[i][j][prev] + 1)) {
        q.emplace(ni, nj, d);
      }
    }
  }
  int ans = inf;
  rep(d, 0, 4) chmin(ans, dist[gi][gj][d]);
  cout << (ans == inf ? -1 : ans) << '\n';
}
