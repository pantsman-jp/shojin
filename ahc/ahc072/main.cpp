#include <algorithm>
#include <chrono>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;

struct Move {
  int r, c, keep, len;
  char dir;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<string> board(n);
  for (int i = 0; i < n; ++i) cin >> board[i];
  const int V = n * n;
  const int dr[4] = {-1, 1, 0, 0};
  const int dc[4] = {0, 0, -1, 1};
  const char dch[4] = {'U', 'D', 'L', 'R'};
  const int INF = 1e9;
  auto id = [n](int r, int c) { return r * n + c; };
  auto inside = [n](int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < n;
  };
  vector<char> floor_cell(V, 0);
  vector<int> home(k, -1);
  vector<vector<int>> tower(V);
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      int v = id(r, c);
      if (board[r][c] != '#') floor_cell[v] = 1;
      if ('A' <= board[r][c] && board[r][c] <= 'L') {
        home[board[r][c] - 'A'] = v;
      }
      if ('a' <= board[r][c] && board[r][c] <= 'l') {
        tower[v].push_back(board[r][c] - 'a');
      }
    }
  }
  vector<Move> answer;
  constexpr int OP_LIMIT = 100000;
  auto add_move = [&](int from, int keep, int dir, int len) {
    if ((int)answer.size() >= OP_LIMIT) return false;
    answer.push_back({from / n, from % n, keep, len, dch[dir]});
    return true;
  };
  auto auto_home = [&](int v) {
    if (tower[v].empty()) return;
    int h = home[tower[v].back()];
    if (h != v) return;
    int color = tower[v].back();
    while (!tower[v].empty() && tower[v].back() == color) {
      tower[v].pop_back();
    }
  };
  auto apply_move = [&](int src, int keep, int dir, int len) {
    int r = src / n;
    int c = src % n;
    int dst = id(r + dr[dir] * len, c + dc[dir] * len);
    int h = (int)tower[src].size();
    int moving = h - keep;
    vector<int> part;
    part.reserve(moving);
    for (int i = 0; i < moving; ++i) {
      part.push_back(tower[src].back());
      tower[src].pop_back();
    }
    reverse(part.begin(), part.end());
    tower[dst].insert(tower[dst].end(), part.begin(), part.end());
    auto_home(src);
    auto_home(dst);
  };
  auto execute = [&](int src, int keep, int dir, int len) {
    if (!add_move(src, keep, dir, len)) return false;
    apply_move(src, keep, dir, len);
    return true;
  };
  auto single_path = [&](int src, int dst, int forbidden) {
    vector<int> prev(V, -1);
    vector<int> pdir(V, -1);
    vector<int> plen(V, -1);
    queue<int> q;
    prev[src] = src;
    q.push(src);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (v == dst) break;
      int r = v / n;
      int c = v % n;
      for (int z = 0; z < 4; ++z) {
        int nr = r + dr[z];
        int nc = c + dc[z];
        if (!inside(nr, nc)) continue;
        int to = id(nr, nc);
        if (!floor_cell[to] || prev[to] != -1) continue;
        if (to == forbidden) continue;
        if (to != dst && !tower[to].empty()) continue;
        prev[to] = v;
        pdir[to] = z;
        plen[to] = 1;
        q.push(to);
      }
    }
    if (prev[dst] == -1) return vector<pair<int, int>>();
    vector<pair<int, int>> path;
    for (int v = dst; v != src; v = prev[v]) {
      path.push_back({pdir[v], plen[v]});
    }
    reverse(path.begin(), path.end());
    return path;
  };
  auto move_single = [&](int src, int dst) {
    if (src == dst) return true;
    if (tower[src].size() != 1) return false;
    int color = tower[src].back();
    int forbidden = home[color] == dst ? -1 : home[color];
    auto path = single_path(src, dst, forbidden);
    if (path.empty()) return false;
    int cur = src;
    for (auto [dir, len] : path) {
      if (!execute(cur, 0, dir, len)) return false;
      cur = id(cur / n + dr[dir] * len, cur % n + dc[dir] * len);
      if (tower[cur].empty()) return false;
      if (tower[cur].back() != color && cur != dst) return false;
    }
    return cur == dst;
  };
  auto top_path = [&](int src, int dst) {
    int h = (int)tower[src].size();
    vector<int> prev(V, -1);
    vector<int> pdir(V, -1);
    vector<int> plen(V, -1);
    queue<int> q;
    prev[src] = src;
    q.push(src);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (v == dst) break;
      int r = v / n;
      int c = v % n;
      int reach = v == src ? h : 1;
      for (int z = 0; z < 4; ++z) {
        for (int len = 1; len <= reach; ++len) {
          int nr = r + dr[z] * len;
          int nc = c + dc[z] * len;
          if (!inside(nr, nc)) break;
          int to = id(nr, nc);
          if (!floor_cell[to]) break;
          if (prev[to] != -1) continue;
          if (to != dst && !tower[to].empty()) continue;
          if (to == dst && (int)tower[to].size() + 1 > 8) continue;
          prev[to] = v;
          pdir[to] = z;
          plen[to] = len;
          q.push(to);
        }
      }
    }
    if (prev[dst] == -1) return vector<pair<int, int>>();
    vector<pair<int, int>> path;
    for (int v = dst; v != src; v = prev[v]) {
      path.push_back({pdir[v], plen[v]});
    }
    reverse(path.begin(), path.end());
    return path;
  };
  auto move_top_to_home = [&](int src, int color) {
    int dst = home[color];
    if (src == dst) {
      auto_home(src);
      return true;
    }
    auto path = top_path(src, dst);
    if (path.empty()) return false;
    int cur = src;
    for (auto [dir, len] : path) {
      int keep = (int)tower[cur].size() - 1;
      if (!execute(cur, keep, dir, len)) return false;
      cur = id(cur / n + dr[dir] * len, cur % n + dc[dir] * len);
      if (cur == dst) break;
    }
    return true;
  };
  auto collectable = [&](int src, int dst, int color) {
    if (src == dst) return false;
    if (tower[src].size() != 1) return false;
    if (tower[src].back() != color) return false;
    if ((int)tower[dst].size() >= 8) return false;
    int forbidden = home[color] == dst ? -1 : home[color];
    auto path = single_path(src, dst, forbidden);
    return !path.empty();
  };
  const auto start_time = chrono::steady_clock::now();
  auto elapsed_ms = [&]() {
    return chrono::duration_cast<chrono::milliseconds>(
               chrono::steady_clock::now() - start_time)
        .count();
  };
  while (elapsed_ms() < 1250 && (int)answer.size() < OP_LIMIT) {
    vector<vector<int>> by_color(k);
    for (int v = 0; v < V; ++v) {
      if (tower[v].size() == 1) {
        by_color[tower[v].back()].push_back(v);
      }
    }
    int best_seed = -1;
    int best_color = -1;
    vector<int> best_members;
    int best_score = 0;
    for (int color = 0; color < k; ++color) {
      if ((int)by_color[color].size() < 2) continue;
      for (int seed : by_color[color]) {
        if (seed == home[color]) continue;
        vector<pair<int, int>> candidates;
        for (int s : by_color[color]) {
          if (s == seed) continue;
          if (!collectable(s, seed, color)) continue;
          auto path = single_path(s, seed, home[color]);
          if (path.empty()) continue;
          candidates.push_back({(int)path.size(), s});
        }
        sort(candidates.begin(), candidates.end());
        int limit = min(7, (int)candidates.size());
        int single_cost = 0;
        for (int s : by_color[color]) {
          auto path = single_path(s, home[color], seed);
          if (!path.empty()) single_cost += (int)path.size();
        }
        int batch_cost = 0;
        vector<int> members;
        for (int i = 0; i < limit; ++i) {
          int s = candidates[i].second;
          batch_cost += candidates[i].first;
          members.push_back(s);
          int h = 1 + (int)members.size();
          if (h > 8) break;
          int estimated_home = 0;
          if (h >= 2) {
            auto path = top_path(seed, home[color]);
            if (!path.empty()) estimated_home = (int)path.size();
          }
          int saving = single_cost - batch_cost - estimated_home;
          if (saving > best_score) {
            best_score = saving;
            best_seed = seed;
            best_color = color;
            best_members = members;
          }
        }
      }
    }
    if (best_seed == -1 || best_score <= 0) break;
    vector<int> members = best_members;
    for (int s : members) {
      if (tower[s].size() != 1) continue;
      if (tower[s].back() != best_color) continue;
      move_single(s, best_seed);
    }
    if (tower[best_seed].empty()) continue;
    while (!tower[best_seed].empty() && tower[best_seed].back() == best_color &&
           (int)answer.size() < OP_LIMIT) {
      int before = (int)tower[best_seed].size();
      if (!move_top_to_home(best_seed, best_color)) {
        break;
      }
      if ((int)tower[best_seed].size() == before) break;
    }
  }
  for (int v = 0; v < V && (int)answer.size() < OP_LIMIT; ++v) {
    while (!tower[v].empty() && (int)answer.size() < OP_LIMIT) {
      int color = tower[v].back();
      if (v == home[color]) {
        auto_home(v);
        continue;
      }
      int before = (int)tower[v].size();
      if (!move_top_to_home(v, color)) break;
      if ((int)tower[v].size() == before) break;
    }
  }
  for (const auto& mv : answer) {
    cout << mv.r << ' ' << mv.c << ' ' << mv.keep << ' ' << mv.dir << ' '
         << mv.len << '\n';
  }
  return 0;
}