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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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

int N, M, T;
vector<string> v, h;

struct Point {
  int y, x;
};

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

bool can_move(int y, int x, int d) {
  if (d == 0) return x + 1 < N && v[y][x] == '0';
  if (d == 1) return y + 1 < N && h[y][x] == '0';
  if (d == 2) return x - 1 >= 0 && v[y][x - 1] == '0';
  if (d == 3) return y - 1 >= 0 && h[y - 1][x] == '0';
  return false;
}

struct State {
  int y, x, dir, cost;
  bool operator>(const State& o) const { return cost > o.cost; }
};

vector<int> get_best_path(Point start, int start_dir, Point goal,
                          int& end_dir) {
  vector<vector<vector<int>>> dist(N,
                                   vector<vector<int>>(N, vector<int>(4, 1e9)));
  vector<vector<vector<tuple<int, int, int>>>> prev(
      N,
      vector<vector<tuple<int, int, int>>>(N, vector<tuple<int, int, int>>(4)));
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.push({start.y, start.x, start_dir, 0});
  dist[start.y][start.x][start_dir] = 0;
  while (!pq.empty()) {
    State s = pq.top();
    pq.pop();
    if (s.cost > dist[s.y][s.x][s.dir]) continue;
    if (s.y == goal.y && s.x == goal.x) continue;
    if (can_move(s.y, s.x, s.dir)) {
      int ny = s.y + dy[s.dir], nx = s.x + dx[s.dir];
      int ncost = s.cost + 1;  // 前進コストを10から1に修正
      if (ncost < dist[ny][nx][s.dir]) {
        dist[ny][nx][s.dir] = ncost;
        prev[ny][nx][s.dir] = {s.y, s.x, s.dir};
        pq.push({ny, nx, s.dir, ncost});
      }
    }
    for (int diff : {-1, 1}) {
      int ndir = (s.dir + diff + 4) % 4;
      int ncost = s.cost + 1;
      if (ncost < dist[s.y][s.x][ndir]) {
        dist[s.y][s.x][ndir] = ncost;
        prev[s.y][s.x][ndir] = {s.y, s.x, s.dir};
        pq.push({s.y, s.x, ndir, ncost});
      }
    }
  }
  int min_cost = 1e9;
  int best_edir = -1;
  for (int d = 0; d < 4; d++) {
    if (dist[goal.y][goal.x][d] < min_cost) {
      min_cost = dist[goal.y][goal.x][d];
      best_edir = d;
    }
  }
  vector<int> path_ops;
  int cy = goal.y, cx = goal.x, cd = best_edir;
  end_dir = cd;
  while (cy != start.y || cx != start.x || cd != start_dir) {
    auto [py, px, pd] = prev[cy][cx][cd];
    if (py != cy || px != cx)
      path_ops.push_back(0);
    else if ((pd + 1) % 4 == cd)
      path_ops.push_back(1);
    else
      path_ops.push_back(2);
    cy = py;
    cx = px;
    cd = pd;
  }
  reverse(path_ops.begin(), path_ops.end());
  return path_ops;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  auto start_time = chrono::system_clock::now();
  if (!(cin >> N >> M >> T)) return 0;
  v.resize(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  h.resize(N - 1);
  for (int i = 0; i < N - 1; i++) cin >> h[i];
  vector<Point> balls(M), baskets(M);
  for (int i = 0; i < M; i++)
    cin >> balls[i].y >> balls[i].x >> baskets[i].y >> baskets[i].x;
  vector<Point> nodes(2 * M + 1);
  nodes[2 * M] = {0, 0};
  for (int i = 0; i < M; i++) {
    nodes[i] = balls[i];
    nodes[i + M] = baskets[i];
  }
  vector<vector<int>> D(2 * M + 1, vector<int>(2 * M + 1, 0));
  for (int i = 0; i <= 2 * M; i++) {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<Point> q;
    q.push(nodes[i]);
    dist[nodes[i].y][nodes[i].x] = 0;
    while (!q.empty()) {
      Point p = q.front();
      q.pop();
      for (int d = 0; d < 4; d++) {
        if (can_move(p.y, p.x, d)) {
          int ny = p.y + dy[d], nx = p.x + dx[d];
          if (dist[ny][nx] == -1) {
            dist[ny][nx] = dist[p.y][p.x] + 1;
            q.push({ny, nx});
          }
        }
      }
    }
    for (int j = 0; j <= 2 * M; j++) {
      D[i][j] = dist[nodes[j].y][nodes[j].x];
    }
  }
  vector<int> best_order(M);
  iota(best_order.begin(), best_order.end(), 0);
  mt19937 rng(42);
  auto calc_score = [&](const vector<int>& order) {
    int score = 0, curr = 2 * M;
    for (int i = 0; i < M; i++) {
      score += D[curr][order[i]];
      curr = order[i];
      score += D[curr][order[i] + M];
      curr = order[i] + M;
    }
    return score;
  };
  int best_score = calc_score(best_order);
  vector<int> current_order = best_order;
  int current_score = best_score;
  double temp_start = 100.0, temp_end = 0.1;
  while (true) {
    auto current_time = chrono::system_clock::now();
    double elapsed =
        chrono::duration_cast<chrono::milliseconds>(current_time - start_time)
            .count() /
        1000.0;
    if (elapsed > 1.7) break;
    bool is_swap = (rng() % 2 == 0);
    int u = rng() % M;
    int v_idx = rng() % M;
    if (u == v_idx) continue;
    if (is_swap) {
      swap(current_order[u], current_order[v_idx]);
    } else {
      if (u > v_idx) swap(u, v_idx);
      reverse(current_order.begin() + u, current_order.begin() + v_idx + 1);
    }
    int new_score = calc_score(current_order);
    double temp = temp_start + (temp_end - temp_start) * (elapsed / 1.7);
    if (new_score < current_score ||
        exp((current_score - new_score) / temp) > ((double)rng() / rng.max())) {
      current_score = new_score;
      if (current_score < best_score) {
        best_score = current_score;
        best_order = current_order;
      }
    } else {
      if (is_swap) {
        swap(current_order[u], current_order[v_idx]);
      } else {
        reverse(current_order.begin() + u, current_order.begin() + v_idx + 1);
      }
    }
  }
  string raw_ops = "";
  int curr_dir = 0, cy = 0, cx = 0;
  for (int i = 0; i < M; i++) {
    int idx = best_order[i];
    vector<int> p1 = get_best_path({cy, cx}, curr_dir, balls[idx], curr_dir);
    for (int op : p1) {
      if (op == 0)
        raw_ops += "F";
      else if (op == 1)
        raw_ops += "R";
      else
        raw_ops += "L";
    }
    raw_ops += "S";
    cy = balls[idx].y;
    cx = balls[idx].x;
    vector<int> p2 = get_best_path({cy, cx}, curr_dir, baskets[idx], curr_dir);
    for (int op : p2) {
      if (op == 0)
        raw_ops += "F";
      else if (op == 1)
        raw_ops += "R";
      else
        raw_ops += "L";
    }
    raw_ops += "S";
    cy = baskets[idx].y;
    cx = baskets[idx].x;
  }
  int L = raw_ops.length();
  string best_sub = "";
  int max_saved = 0;
  int max_len_to_check = L / 2;
  for (int len = 3; len <= max_len_to_check; len++) {
    unordered_map<string, int> cnt;
    for (int i = 0; i <= L - len; i++) {
      cnt[raw_ops.substr(i, len)]++;
    }
    for (const auto& p : cnt) {
      if (p.second > 1) {
        int count = 0;
        const string& sub = p.first;
        for (int j = 0; j <= L - len;) {
          if (raw_ops.substr(j, len) == sub) {
            count++;
            j += len;
          } else {
            j++;
          }
        }
        if (count > 1) {
          int saved = (len - 1) * (count - 1) - 2;
          if (saved > max_saved) {
            max_saved = saved;
            best_sub = sub;
          }
        }
      }
    }
  }
  string final_ops = "";
  if (max_saved > 0) {
    bool first = true;
    for (int i = 0; i < L;) {
      if (i <= L - (int)best_sub.length() &&
          raw_ops.substr(i, best_sub.length()) == best_sub) {
        if (first) {
          final_ops += "M" + best_sub + "M";
          first = false;
        } else {
          final_ops += "P";
        }
        i += best_sub.length();
      } else {
        final_ops += raw_ops[i];
        i++;
      }
    }
  } else {
    final_ops = raw_ops;
  }
  int limit = min((int)final_ops.length(), T);
  for (int i = 0; i < limit; i++) {
    cout << final_ops[i] << '\n';
  }
  return 0;
}