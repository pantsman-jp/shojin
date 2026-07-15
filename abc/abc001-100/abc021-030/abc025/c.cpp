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

vector<vector<int>> b(2, vector<int>(3)), c(3, vector<int>(2));

int score(const vector<int>& board) {
  auto mass = [&](int i, int j) -> int { return i * 3 + j; };
  int res = 0;
  rep(i, 0, 2) rep(j, 0, 3) {
    if (board[mass(i, j)] == board[mass(i + 1, j)])
      res -= b[i][j];
    else
      res += b[i][j];
  }
  rep(i, 0, 3) rep(j, 0, 2) {
    if (board[mass(i, j)] == board[mass(i, j + 1)])
      res -= c[i][j];
    else
      res += c[i][j];
  }
  return res;
}

map<vector<int>, int> dp;

int dfs(vector<int>& board, int tesuu) {
  if (dp.count(board)) return dp[board];
  if (tesuu == 9) return dp[board] = score(board);
  int res = -inf;
  for (int i = 0; i < 9; ++i) {
    if (board[i] != -1) continue;
    board[i] = (tesuu % 2 == 0 ? 1 : 0);
    chmax(res, -dfs(board, tesuu + 1));
    board[i] = -1;
  }
  return dp[board] = res;
}

void solve() {
  int sum = 0;
  rep(i, 0, 2) rep(j, 0, 3) {
    cin >> b[i][j];
    sum += b[i][j];
  }
  rep(i, 0, 3) rep(j, 0, 2) {
    cin >> c[i][j];
    sum += c[i][j];
  }
  vector<int> board(9, -1);
  int diff = dfs(board, 0);
  cout << (sum + diff) / 2 << '\n' << (sum - diff) / 2 << '\n';
}