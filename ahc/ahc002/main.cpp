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

string ans, best_ans, current_ans;
ll score, best_score, current_score;

void dfs(int i, int j, TimeKeeper& tk) {
  while (!tk.is_time_over()) {
    array<int, 4> order = {0, 1, 2, 3};
    shuffle(all(order), rng);
    bool moved = false;
    for (int d : order) {
      int ni = i + di[d], nj = j + dj[d];
      if (out(ni, nj, H, W) || used[t[ni][nj]]) continue;
      used[t[ni][nj]] = true;
      ans += dir(d);
      score += p[ni][nj];
      i = ni;
      j = nj;
      moved = true;
      break;
    }
    if (!moved) break;
  }
}

int rev_dir(char c) {
  if (c == 'U') return 0;
  if (c == 'R') return 1;
  if (c == 'D') return 2;
  return 3;
}

void solve() {
  TimeKeeper tk(1950);
  fill(all(used), false);
  used[t[si][sj]] = true;
  score = p[si][sj];
  ans.clear();
  dfs(si, sj, tk);
  current_ans = ans;
  current_score = score;
  best_ans = ans;
  best_score = score;
  const double T0 = 100.0;
  const double T1 = 1.0;
  while (!tk.is_time_over()) {
    int cut = randrange(0, (int)current_ans.size() + 1);
    fill(all(used), false);
    used[t[si][sj]] = true;
    int i = si, j = sj;
    score = p[si][sj];
    ans = current_ans.substr(0, cut);
    rep(k, 0, cut) {
      int d = rev_dir(current_ans[k]);
      i += di[d];
      j += dj[d];
      used[t[i][j]] = true;
      score += p[i][j];
    }
    dfs(i, j, tk);
    if (tk.is_time_over()) break;
    if (chmax(best_score, score)) {
      best_ans = ans;
    }
    double progress = tk.elapsed() / 1900.0;
    double temp = T0 + (T1 - T0) * progress;
    ll diff = score - current_score;
    if (diff >= 0 || randdouble() < exp((double)diff / temp)) {
      current_ans = ans;
      current_score = score;
    }
  }
  cout << best_ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}
