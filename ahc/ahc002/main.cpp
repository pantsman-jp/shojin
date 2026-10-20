// Template: https://github.com/pantsman-jp/shojin/blob/main/ahc/template/main.cpp
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// [l, r)
int randrange(int l, int r) {
  return uniform_int_distribution<int>(l, r - 1)(rng);
}

// [0.0, 1.0)
double randdouble() { return uniform_real_distribution<double>(0.0, 1.0)(rng); }

using Clock = chrono::steady_clock;
using Timer = chrono::time_point<Clock>;
// 使用例
// TimeKeeper tk(1900);             // 制限時間を1900 msに設定
// tk.elapsed();                    // 経過時間をmsで取得
// tk.remaining();                  // 残り時間をmsで取得
// tk.is_time_over();               // 制限時間を超えたか判定
// while (!tk.is_time_over()) { ... }  // 制限時間内で探索
struct TimeKeeper {
  Timer start;
  double time_limit;
  explicit TimeKeeper(double time_limit_ms)
      : start(Clock::now()), time_limit(time_limit_ms) {}
  double elapsed() const {
    return chrono::duration<double, milli>(Clock::now() - start).count();
  }
  double remaining() const { return max(0.0, time_limit - elapsed()); }
  bool is_time_over() const { return elapsed() >= time_limit; }
};

int si, sj;

const int H = 50, W = 50;
vector t(H, vector<int>(W)), p(H, vector<int>(W));

void input() {
  cin >> si >> sj;
  rep(i, 0, H) rep(j, 0, W) cin >> t[i][j];
  rep(i, 0, H) rep(j, 0, W) cin >> p[i][j];
}

vector<bool> used(H* W);

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

string dir(int d) {
  if (d == 0) {
    return "U";
  } else if (d == 1) {
    return "R";
  } else if (d == 2) {
    return "D";
  }
  return "L";
}

string ans;

void dfs(int i, int j) {
  rep(d, 0, 4) {
    int ni = i + di[d], nj = j + dj[d];
    if (out(ni, nj, H, W) or used[t[ni][nj]]) continue;
    used[t[ni][nj]] = true;
    ans += dir(d);
    dfs(ni, nj);
    return;
  }
}

void solve() {
  used[t[si][sj]] = true;
  dfs(si, sj);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}
