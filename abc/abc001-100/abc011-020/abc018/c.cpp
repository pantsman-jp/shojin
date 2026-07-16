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

const vector<int> dy = {-1, 0, 1, 0};
const vector<int> dx = {0, 1, 0, -1};

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

void solve() {
  int r, c, k;
  cin >> r >> c >> k;
  vector grid(r, vector<bool>(c, true));
  rep(i, 0, r) rep(j, 0, c) {
    char s;
    cin >> s;
    if (s == 'x') grid[i][j] = false;
  }
  rep(i, 0, k - 1) {
    vector old(r, vector<bool>(c));
    swap(old, grid);
    rep(y, 0, r) rep(x, 0, c) {
      bool b = old[y][x];
      rep(j, 0, 4) {
        int ny = y + dy[j], nx = x + dx[j];
        if (out(ny, nx, r, c)) {
          b = false;
        } else {
          b &= old[ny][nx];
        }
      }
      grid[y][x] = b;
    }
  }
  int ans = 0;
  rep(i, 0, r) rep(j, 0, c) ans += grid[i][j];
  cout << ans << '\n';
}