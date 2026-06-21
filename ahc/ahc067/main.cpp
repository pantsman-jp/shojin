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

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

int turn_id = 0;
int visited[1024][20][20];
int door_h[20][20];
int door_v[20][20];
int sw_board[20][20];
int door_cnt = 0;
int sw_cnt = 0;

int best_score = -1;
int best_door_h[20][20];
int best_door_v[20][20];
int best_sw[20][20];

void init_boards() {
  memset(visited, 0, sizeof(visited));
  memset(door_h, -1, sizeof(door_h));
  memset(door_v, -1, sizeof(door_v));
  memset(sw_board, -1, sizeof(sw_board));
}

void save_best() {
  rep(i, 0, 20) rep(j, 0, 20) {
    best_door_h[i][j] = door_h[i][j];
    best_door_v[i][j] = door_v[i][j];
    best_sw[i][j] = sw_board[i][j];
  }
}

inline void apply_door(int d, int i, int j, int g) {
  if (d == 0) {
    if (door_h[i][j] == -1 && g != -1) door_cnt++;
    if (door_h[i][j] != -1 && g == -1) door_cnt--;
    door_h[i][j] = g;
  } else {
    if (door_v[i][j] == -1 && g != -1) door_cnt++;
    if (door_v[i][j] != -1 && g == -1) door_cnt--;
    door_v[i][j] = g;
  }
}

inline void apply_switch(int i, int j, int s) {
  if (sw_board[i][j] == -1 && s != -1) sw_cnt++;
  if (sw_board[i][j] != -1 && s == -1) sw_cnt--;
  sw_board[i][j] = s;
}

int q_state[410000];
int q_d[410000];

int calc_T(const vector<string>& c) {
  int N = c.size();
  turn_id++;
  int head = 0, tail = 0;
  auto push = [&](int d, int mask, int i, int j) {
    if (visited[mask][i][j] == turn_id) return;
    visited[mask][i][j] = turn_id;
    q_state[tail] = (mask << 10) | (i << 5) | j;
    q_d[tail] = d;
    tail++;
  };
  push(0, 0, 0, 0);
  int res = 0;
  while (head < tail) {
    int val = q_state[head];
    int d = q_d[head];
    head++;
    int j = val & 31;
    int i = (val >> 5) & 31;
    int mask = (val >> 10) & 1023;
    if (i == N - 1 && j == N - 1) {
      res = d;
      break;
    }
    rep(dir, 0, 4) {
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
      if (c[ni][nj] == '#') continue;
      int g = -1;
      if (dir == 0)
        g = door_h[ni][nj];
      else if (dir == 1)
        g = door_v[i][j];
      else if (dir == 2)
        g = door_h[i][j];
      else
        g = door_v[ni][nj];
      if (g != -1) {
        int k = g >> 1;
        if (((mask >> k) & 1) != (g & 1)) continue;
      }
      push(d + 1, mask, ni, nj);
    }
    int s = sw_board[i][j];
    if (s != -1) {
      int nmask = mask ^ (1 << s);
      push(d + 1, nmask, i, j);
    }
  }
  return res;
}

vector<pii> random_path(const vector<string>& c, mt19937& rng) {
  int N = c.size();
  vector dist(N, vector<int>(N, inf));
  vector pre(N, vector<pii>(N, {-1, -1}));
  using state = pair<int, pii>;
  rpq<state> q;
  vector weight(N, vector<int>(N, 1));
  rep(i, 0, N) {
    rep(j, 0, N) { weight[i][j] = uniform_int_distribution<int>(1, 10)(rng); }
  }
  q.push({0, {0, 0}});
  dist[0][0] = 0;
  while (!q.empty()) {
    auto [d, u] = q.top();
    auto [i, j] = u;
    q.pop();
    if (dist[i][j] < d) continue;
    rep(dir, 0, 4) {
      int ni = i + di[dir];
      int nj = j + dj[dir];
      if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
      if (c[ni][nj] == '#') continue;
      int nd = d + weight[ni][nj];
      if (dist[ni][nj] > nd) {
        dist[ni][nj] = nd;
        pre[ni][nj] = {i, j};
        q.push({nd, {ni, nj}});
      }
    }
  }
  vector<pii> path;
  int i = N - 1;
  int j = N - 1;
  while (!(i == 0 && j == 0)) {
    path.push_back({i, j});
    tie(i, j) = pre[i][j];
  }
  path.push_back({0, 0});
  reverse(all(path));
  return path;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<string> c(N);
  rep(i, 0, N) cin >> c[i];
  vector<pii> valid_sw;
  vector<pair<int, pii>> valid_door;
  rep(i, 0, N) {
    rep(j, 0, N) {
      if (c[i][j] == '.') {
        valid_sw.push_back({i, j});
        if (i + 1 < N && c[i + 1][j] == '.') valid_door.push_back({0, {i, j}});
        if (j + 1 < N && c[i][j + 1] == '.') valid_door.push_back({1, {i, j}});
      }
    }
  }
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  auto start = chrono::steady_clock::now();
  int best_rs_score = -1;
  while (true) {
    auto now = chrono::steady_clock::now();
    double elapsed =
        chrono::duration_cast<chrono::microseconds>(now - start).count() * 1e-6;
    if (elapsed > 0.2) break;
    init_boards();
    door_cnt = 0;
    sw_cnt = 0;
    auto path = random_path(c, rng);
    int L = path.size();
    int cnt = uniform_int_distribution<int>(1, min(10, (L - 1) / 2))(rng);
    vector<int> used(L, 0);
    rep(k, 0, cnt) {
      int p = uniform_int_distribution<int>(0, max(0, L / 2))(rng);
      int q = uniform_int_distribution<int>(max(p + 3, L * 3 / 4), L - 1)(rng);
      if (used[p] || used[q]) continue;
      used[p] = 1;
      used[q] = 1;
      auto [si, sj] = path[q];
      apply_switch(si, sj, k);
      auto [a_i, a_j] = path[p];
      auto [b_i, b_j] = path[p + 1];
      int d = (a_i == b_i) ? 1 : 0;
      if (d == 0)
        apply_door(0, min(a_i, b_i), a_j, 2 * k + 1);
      else
        apply_door(1, a_i, min(a_j, b_j), 2 * k + 1);
    }
    int score = calc_T(c);
    if (score > best_rs_score) {
      best_rs_score = score;
      save_best();
    }
  }
  rep(i, 0, 20) rep(j, 0, 20) {
    door_h[i][j] = best_door_h[i][j];
    door_v[i][j] = best_door_v[i][j];
    sw_board[i][j] = best_sw[i][j];
  }
  door_cnt = 0;
  sw_cnt = 0;
  rep(i, 0, 20) rep(j, 0, 20) {
    if (door_h[i][j] != -1) door_cnt++;
    if (door_v[i][j] != -1) door_cnt++;
    if (sw_board[i][j] != -1) sw_cnt++;
  }
  int current_score = best_rs_score;
  best_score = best_rs_score;
  double temp0 = 5.0;
  double temp1 = 0.0;
  double current_temp = temp0;
  int iter = 0;
  while (true) {
    if ((iter & 127) == 0) {
      auto now = chrono::steady_clock::now();
      double elapsed =
          chrono::duration_cast<chrono::microseconds>(now - start).count() *
          1e-6;
      if (elapsed > 1.95) break;
      current_temp = temp0 + (temp1 - temp0) * ((elapsed - 0.2) / 1.75);
      if (current_temp < 0.0) current_temp = 0.0;
    }
    iter++;
    int r = uniform_int_distribution<int>(0, 99)(rng);
    int type = -1;
    if (r < 40)
      type = 0;
    else if (r < 50)
      type = 1;
    else if (r < 90)
      type = 2;
    else
      type = 3;
    int d = -1, i = -1, j = -1, g = -1, s = -1;
    int old_g = -1, old_s = -1;
    if (type == 0) {
      if (valid_door.empty()) continue;
      auto [td, pos] = valid_door[uniform_int_distribution<int>(
          0, valid_door.size() - 1)(rng)];
      d = td;
      i = pos.first;
      j = pos.second;
      g = uniform_int_distribution<int>(0, 2 * K - 1)(rng);
      old_g = (d == 0) ? door_h[i][j] : door_v[i][j];
      if (old_g == -1 && door_cnt == M) continue;
      apply_door(d, i, j, g);
    } else if (type == 1) {
      if (door_cnt == 0 || valid_door.empty()) continue;
      while (true) {
        auto [td, pos] = valid_door[uniform_int_distribution<int>(
            0, valid_door.size() - 1)(rng)];
        d = td;
        i = pos.first;
        j = pos.second;
        old_g = (d == 0) ? door_h[i][j] : door_v[i][j];
        if (old_g != -1) break;
      }
      apply_door(d, i, j, -1);
    } else if (type == 2) {
      if (valid_sw.empty()) continue;
      auto pos =
          valid_sw[uniform_int_distribution<int>(0, valid_sw.size() - 1)(rng)];
      i = pos.first;
      j = pos.second;
      s = uniform_int_distribution<int>(0, K - 1)(rng);
      old_s = sw_board[i][j];
      apply_switch(i, j, s);
    } else {
      if (sw_cnt == 0 || valid_sw.empty()) continue;
      while (true) {
        auto pos = valid_sw[uniform_int_distribution<int>(
            0, valid_sw.size() - 1)(rng)];
        i = pos.first;
        j = pos.second;
        old_s = sw_board[i][j];
        if (old_s != -1) break;
      }
      apply_switch(i, j, -1);
    }
    int score = calc_T(c);
    bool accept = false;
    if (score > 0) {
      if (score >= current_score) {
        accept = true;
      } else {
        if (uniform_real_distribution<double>(0.0, 1.0)(rng) <
            exp((score - current_score) / current_temp)) {
          accept = true;
        }
      }
    }
    if (accept) {
      current_score = score;
      if (score > best_score) {
        best_score = score;
        save_best();
      }
    } else {
      if (type == 0 || type == 1)
        apply_door(d, i, j, old_g);
      else
        apply_switch(i, j, old_s);
    }
  }
  vector<tuple<int, int, int, int>> ans_doors;
  rep(i, 0, 20) rep(j, 0, 20) {
    if (best_door_h[i][j] != -1)
      ans_doors.push_back({0, i, j, best_door_h[i][j]});
    if (best_door_v[i][j] != -1)
      ans_doors.push_back({1, i, j, best_door_v[i][j]});
  }
  cout << ans_doors.size() << '\n';
  for (auto [d, i, j, g] : ans_doors) {
    cout << d << ' ' << i << ' ' << j << ' ' << g << '\n';
  }
  vector<tuple<int, int, int>> ans_sw;
  rep(i, 0, 20) rep(j, 0, 20) {
    if (best_sw[i][j] != -1) ans_sw.push_back({i, j, best_sw[i][j]});
  }
  cout << ans_sw.size() << '\n';
  for (auto [i, j, s] : ans_sw) {
    cout << i << ' ' << j << ' ' << s << '\n';
  }
  return 0;
}