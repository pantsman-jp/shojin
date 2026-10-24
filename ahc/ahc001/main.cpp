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

const int H = 10000, W = 10000;
int n;
vector<ll> x, y, r;

void input() {
  cin >> n;
  x.resize(n), y.resize(n), r.resize(n);
  rep(i, 0, n) cin >> x[i] >> y[i] >> r[i];
}

struct Rect {
  ll x1, y1, x2, y2;
};

void output(const Rect& a) {
  cout << a.x1 << ' ' << a.y1 << ' ' << a.x2 << ' ' << a.y2 << '\n';
}

ll area(const Rect& a) {
  return (a.x2 - a.x1) * (a.y2 - a.y1);
}

bool is_overlap(const Rect& a, const Rect& b) {
  return (a.x1 < b.x2) && (b.x1 < a.x2) && (a.y1 < b.y2) && (b.y1 < a.y2);
}

bool is_in(const Rect& a) {
  return (0 <= a.x1) and (0 <= a.y1) and (a.x2 <= W) and (a.y2 <= H);
}

ld satisfaction(const Rect& a, ll target) {
  ld s = area(a) * 1.0;
  ld r = target * 1.0;
  ld tmp = 1.0 - min(r, s) / max(r, s);
  return 1.0 - tmp * tmp;
}

ld score(const vector<Rect>& xs) {
  ld res = 0.0;
  rep(i, 0, n) res += satisfaction(xs[i], r[i]);
  return res;
}

void solve() {
  vector<Rect> ans;
  rep(i, 0, n) {
    ans.emplace_back(Rect{x[i], y[i], x[i] + 1, y[i] + 1});
  }
  TimeKeeper tk(4990);
  while (!tk.is_time_over()) {
    ld now = score(ans);
    auto copy = ans;
    int d = randrange(0, 4);
    int i = randrange(0, n);
    if (d == 0) {
      copy[i].x1 = randrange(0, x[i] + 1);
    } else if (d == 1) {
      copy[i].x2 = randrange(x[i] + 1, W + 1);
    } else if (d == 2) {
      copy[i].y1 = randrange(0, y[i] + 1);
    } else {
      copy[i].y2 = randrange(y[i] + 1, H + 1);
    }
    if (is_in(copy[i])) {
      bool ok = true;
      rep(j, 0, n) {
        if (i == j) continue;
        if (is_overlap(copy[i], ans[j])) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ld next = now - satisfaction(ans[i], r[i]) + satisfaction(copy[i], r[i]);
        if (now < next) ans = copy;
      }
    }
  }
  for (auto x : ans) output(x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  input();
  solve();
  return 0;
}
