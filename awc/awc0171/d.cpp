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

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

void solve() {
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  vector dist(h, vector(w, vector<int>(2, inf)));
  queue<tuple<int, int, int>> q;
  dist[0][0][0] = 0;
  dist[0][0][1] = 0;
  q.emplace(0, 0, 0);
  q.emplace(0, 0, 1);
  while (!q.empty()) {
    auto [i, j, t] = q.front();
    q.pop();
    if (t == 0) {
      for (auto [di, dj] : vector<pii>{{1, 0}, {-1, 0}}) {
        int ni = i + di, nj = j + dj;
        if (out(ni, nj, h, w) or a[ni][nj] == 1) continue;
        if (chmin(dist[ni][nj][1], dist[i][j][0] + 1)) {
          q.emplace(ni, nj, 1);
        }
      }
    } else {
      for (auto [di, dj] : vector<pii>{{0, 1}, {0, -1}}) {
        int ni = i + di, nj = j + dj;
        if (out(ni, nj, h, w) or a[ni][nj] == 1) continue;
        if (chmin(dist[ni][nj][0], dist[i][j][1] + 1)) {
          q.emplace(ni, nj, 0);
        }
      }
    }
  }
  int ans = min(dist[h - 1][w - 1][0], dist[h - 1][w - 1][1]);
  if (ans == inf) {
    cout << "NONE\n";
  } else {
    cout << ans << '\n';
  }
}
