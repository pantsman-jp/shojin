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

struct Route {
  vector<int> dist;
  vector<int> prev;
  vector<int> pdir;
  vector<int> plen;
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
  vector<int> floor_cell(V, 0), home(k, -1), occ(V, -1);
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < n; ++c) {
      const int v = id(r, c);
      if (board[r][c] != '#') floor_cell[v] = 1;
      if ('A' <= board[r][c] && board[r][c] <= 'L') {
        home[board[r][c] - 'A'] = v;
      }
      if ('a' <= board[r][c] && board[r][c] <= 'l') {
        occ[v] = board[r][c] - 'a';
      }
    }
  }
  vector<vector<int>> grid_dist(V, vector<int>(V, INF));
  for (int s = 0; s < V; ++s) {
    if (!floor_cell[s]) continue;
    queue<int> q;
    grid_dist[s][s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      int r = v / n, c = v % n;
      for (int z = 0; z < 4; ++z) {
        int nr = r + dr[z], nc = c + dc[z];
        if (!inside(nr, nc)) continue;
        int to = id(nr, nc);
        if (!floor_cell[to] || grid_dist[s][to] != INF) continue;
        grid_dist[s][to] = grid_dist[s][v] + 1;
        q.push(to);
      }
    }
  }
  auto single_route = [&](int src, bool with_parent, int forbidden = -1) {
    Route ret;
    ret.dist.assign(V, INF);
    if (with_parent) {
      ret.prev.assign(V, -1);
      ret.pdir.assign(V, -1);
      ret.plen.assign(V, -1);
    }
    queue<int> q;
    ret.dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      int reach = (v != src && occ[v] != -1) ? 2 : 1;
      int r = v / n, c = v % n;
      for (int z = 0; z < 4; ++z) {
        for (int len = 1; len <= reach; ++len) {
          int nr = r + dr[z] * len, nc = c + dc[z] * len;
          if (!inside(nr, nc)) break;
          int to = id(nr, nc);
          if (!floor_cell[to]) break;
          if (to == forbidden) continue;
          if (ret.dist[to] != INF) continue;
          ret.dist[to] = ret.dist[v] + 1;
          if (with_parent) {
            ret.prev[to] = v;
            ret.pdir[to] = z;
            ret.plen[to] = len;
          }
          q.push(to);
        }
      }
    }
    return ret;
  };
  auto grid_path = [&](int src, int dst) {
    vector<int> prev(V, -1), pdir(V, -1);
    queue<int> q;
    prev[src] = src;
    q.push(src);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (v == dst) break;
      int r = v / n, c = v % n;
      for (int z = 0; z < 4; ++z) {
        int nr = r + dr[z], nc = c + dc[z];
        if (!inside(nr, nc)) continue;
        int to = id(nr, nc);
        if (!floor_cell[to] || prev[to] != -1) continue;
        prev[to] = v;
        pdir[to] = z;
        q.push(to);
      }
    }
    vector<pair<int, int>> path;
    for (int v = dst; v != src; v = prev[v]) path.push_back({pdir[v], v});
    reverse(path.begin(), path.end());
    return path;
  };
  vector<Move> answer;
  constexpr int OP_LIMIT = 100000;
  auto add_move = [&](int from, int keep, int dir, int len) {
    if ((int)answer.size() >= OP_LIMIT) return false;
    answer.push_back({from / n, from % n, keep, len, dch[dir]});
    return true;
  };
  auto send_single = [&](int src, int target) {
    const int color = occ[src];
    occ[src] = -1;
    const int forbidden = (target == home[color] ? -1 : home[color]);
    Route route = single_route(src, true, forbidden);
    vector<int> vertices;
    for (int v = target; v != src; v = route.prev[v]) vertices.push_back(v);
    reverse(vertices.begin(), vertices.end());
    int cur = src;
    for (int nxt : vertices) {
      int base = (occ[cur] != -1 ? 1 : 0);
      add_move(cur, base, route.pdir[nxt], route.plen[nxt]);
      cur = nxt;
    }
  };
  const auto start_time = chrono::steady_clock::now();
  auto elapsed_ms = [&]() {
    return chrono::duration_cast<chrono::milliseconds>(
               chrono::steady_clock::now() - start_time)
        .count();
  };
  while (elapsed_ms() < 1350) {
    vector<vector<int>> by_color(k);
    vector<int> alive;
    for (int v = 0; v < V; ++v) {
      if (occ[v] != -1) {
        alive.push_back(v);
        by_color[occ[v]].push_back(v);
      }
    }
    vector<vector<int>> dist_to_batch(V);
    vector<int> direct(V, INF);
    for (int s : alive) {
      const int color = occ[s];
      direct[s] = single_route(s, false).dist[home[color]];
      dist_to_batch[s] = single_route(s, false, home[color]).dist;
    }
    int best_value = 1;
    int best_seed = -1;
    vector<int> best_members;
    for (int color = 0; color < k; ++color) {
      const auto& cells = by_color[color];
      if ((int)cells.size() < 2) continue;
      for (int seed : cells) {
        vector<pair<int, int>> gains;
        for (int s : cells) {
          if (s == seed) continue;
          int gain = direct[s] - dist_to_batch[s][seed];
          if (gain > 0) gains.push_back({gain, s});
        }
        sort(gains.rbegin(), gains.rend());
        int value = direct[seed] - grid_dist[seed][home[color]];
        vector<int> members;
        for (auto [gain, s] : gains) {
          if ((int)members.size() == 6) break;  // seed + 6 <= 7
          value += gain;
          members.push_back(s);
        }
        if (!members.empty() && value > best_value) {
          best_value = value;
          best_seed = seed;
          best_members = members;
        }
      }
    }
    if (best_seed == -1) break;
    const int color = occ[best_seed];
    occ[best_seed] = -1;  // batch tower is intentionally outside occ
    for (int s : best_members) send_single(s, best_seed);
    int cur = best_seed;
    for (auto [z, nxt] : grid_path(best_seed, home[color])) {
      int base = (occ[cur] != -1 ? 1 : 0);
      add_move(cur, base, z, 1);
      cur = nxt;
    }
  }
  for (int s = 0; s < V; ++s) {
    if (occ[s] == -1) continue;
    int color = occ[s];
    send_single(s, home[color]);
  }
  for (const Move& mv : answer) {
    cout << mv.r << ' ' << mv.c << ' ' << mv.keep << ' ' << mv.dir << ' '
         << mv.len << '\n';
  }
  return 0;
}
