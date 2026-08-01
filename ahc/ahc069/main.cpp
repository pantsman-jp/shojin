#include <bits/stdc++.h>
using namespace std;

constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

struct Group {
  int s, t, p, v;
  double compactness = 0.0;
  vector<pair<int, int>> region;
};

struct Candidate {
  vector<pair<int, int>> region;
  double compactness = 0.0;
  double score = -1e100;
  bool ok = false;
};

struct FreeStats {
  int comp_count = 0;
  int largest_comp = 0;
  int free_cells = 0;
};

struct XorShift {
  uint64_t x = 88172645463393265ULL;
  uint32_t next_u32() {
    x ^= x << 7;
    x ^= x >> 9;
    return static_cast<uint32_t>(x & 0xffffffffU);
  }
  int next_int(int l, int r) {
    return l + static_cast<int>(next_u32() % static_cast<uint32_t>(r - l + 1));
  }
};

int N, M;
double R;

vector<string> park;
vector<vector<int>> owner;
vector<Group> groups;
XorShift rng;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    leaving;

inline bool in_grid(int x, int y) { return 0 <= x && x < N && 0 <= y && y < N; }

vector<vector<pair<int, int>>> enumerate_components() {
  vector<vector<pair<int, int>>> comps;
  vector<vector<bool>> vis(N, vector<bool>(N, false));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (vis[i][j]) continue;
      vis[i][j] = true;
      if (park[i][j] == '#' || owner[i][j] != -1) continue;
      queue<pair<int, int>> q;
      q.emplace(i, j);
      vector<pair<int, int>> comp;
      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        comp.emplace_back(x, y);
        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k], ny = y + dy[k];
          if (!in_grid(nx, ny) || vis[nx][ny]) continue;
          vis[nx][ny] = true;
          if (park[nx][ny] == '#' || owner[nx][ny] != -1) continue;
          q.emplace(nx, ny);
        }
      }
      comps.push_back(move(comp));
    }
  }
  return comps;
}

double calc_compactness(const vector<pair<int, int>>& region) {
  if (region.empty()) return 0.0;
  unordered_set<long long> cells;
  cells.reserve(region.size() * 2 + 10);
  for (auto [x, y] : region) {
    cells.insert((1LL * x << 32) | y);
  }
  int perimeter = 0;
  for (auto [x, y] : region) {
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (!cells.count((1LL * nx << 32) | ny)) {
        perimeter++;
      }
    }
  }
  return 4.0 * sqrt((double)region.size()) / perimeter;
}

double calc_future_bonus(const vector<pair<int, int>>& region) {
  // 盤面中央に小サイズを寄せすぎるのを避けるため、辺への近さを少し加点する。
  double sum_edge = 0.0;
  for (auto [x, y] : region) {
    int d = min(min(x, N - 1 - x), min(y, N - 1 - y));
    sum_edge += d;
  }
  double avg_edge = sum_edge / max(1, (int)region.size());
  return -avg_edge;
}

vector<pair<int, int>> build_by_bfs(const vector<pair<int, int>>& comp,
                                    const pair<int, int>& seed, int p) {
  unordered_set<long long> in_comp;
  in_comp.reserve(comp.size() * 2 + 10);
  for (auto [x, y] : comp) in_comp.insert((1LL * x << 32) | y);
  queue<pair<int, int>> q;
  unordered_set<long long> vis;
  vis.reserve(comp.size() * 2 + 10);
  vector<pair<int, int>> region;
  q.push(seed);
  vis.insert((1LL * seed.first << 32) | seed.second);
  while (!q.empty() && (int)region.size() < p) {
    auto [x, y] = q.front();
    q.pop();
    region.emplace_back(x, y);
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      long long key = (1LL * nx << 32) | ny;
      if (!in_grid(nx, ny)) continue;
      if (!in_comp.count(key)) continue;
      if (vis.count(key)) continue;
      vis.insert(key);
      q.emplace(nx, ny);
    }
  }
  if ((int)region.size() != p) return {};
  return region;
}

vector<pair<int, int>> build_by_dfs(const vector<pair<int, int>>& comp,
                                    const pair<int, int>& seed, int p) {
  unordered_set<long long> in_comp;
  in_comp.reserve(comp.size() * 2 + 10);
  for (auto [x, y] : comp) in_comp.insert((1LL * x << 32) | y);
  vector<pair<int, int>> st;
  unordered_set<long long> vis;
  vis.reserve(comp.size() * 2 + 10);
  vector<pair<int, int>> region;
  st.push_back(seed);
  vis.insert((1LL * seed.first << 32) | seed.second);
  while (!st.empty() && (int)region.size() < p) {
    auto [x, y] = st.back();
    st.pop_back();
    region.emplace_back(x, y);
    for (int k = 3; k >= 0; k--) {
      int nx = x + dx[k], ny = y + dy[k];
      long long key = (1LL * nx << 32) | ny;
      if (!in_grid(nx, ny)) continue;
      if (!in_comp.count(key)) continue;
      if (vis.count(key)) continue;
      vis.insert(key);
      st.emplace_back(nx, ny);
    }
  }
  if ((int)region.size() != p) return {};
  return region;
}

vector<pair<int, int>> build_by_growing(const vector<pair<int, int>>& comp,
                                        const pair<int, int>& seed, int p) {
  unordered_set<long long> in_comp;
  in_comp.reserve(comp.size() * 2 + 10);
  for (auto [x, y] : comp) in_comp.insert((1LL * x << 32) | y);

  auto center_dist2 = [&](int x, int y) {
    int dx0 = x - seed.first;
    int dy0 = y - seed.second;
    return dx0 * dx0 + dy0 * dy0;
  };

  vector<pair<int, int>> region;
  region.reserve(p);
  unordered_set<long long> used;
  used.reserve(p * 2 + 10);
  unordered_set<long long> frontier;
  frontier.reserve(p * 8 + 10);

  region.push_back(seed);
  used.insert((1LL * seed.first << 32) | seed.second);
  for (int k = 0; k < 4; k++) {
    int nx = seed.first + dx[k], ny = seed.second + dy[k];
    long long key = (1LL * nx << 32) | ny;
    if (!in_grid(nx, ny)) continue;
    if (!in_comp.count(key)) continue;
    frontier.insert(key);
  }

  while ((int)region.size() < p && !frontier.empty()) {
    long long best_key = -1;
    int best_deg = -1;
    int best_d2 = (1 << 30);
    for (long long key : frontier) {
      int x = (int)(key >> 32);
      int y = (int)(key & 0xffffffffLL);
      int deg = 0;
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        long long nkey = (1LL * nx << 32) | ny;
        if (!in_grid(nx, ny)) continue;
        if (!in_comp.count(nkey)) continue;
        if (used.count(nkey)) deg++;
      }
      int d2 = center_dist2(x, y);
      if (deg > best_deg || (deg == best_deg && d2 < best_d2)) {
        best_deg = deg;
        best_d2 = d2;
        best_key = key;
      }
    }

    frontier.erase(best_key);
    int x = (int)(best_key >> 32);
    int y = (int)(best_key & 0xffffffffLL);
    if (used.count(best_key)) continue;
    used.insert(best_key);
    region.emplace_back(x, y);
    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k], ny = y + dy[k];
      long long nkey = (1LL * nx << 32) | ny;
      if (!in_grid(nx, ny)) continue;
      if (!in_comp.count(nkey)) continue;
      if (!used.count(nkey)) frontier.insert(nkey);
    }
  }
  if ((int)region.size() != p) return {};
  return region;
}

vector<pair<int, int>> build_by_rectangle(const vector<pair<int, int>>& comp,
                                          int p) {
  unordered_set<long long> in_comp;
  in_comp.reserve(comp.size() * 2 + 10);
  for (auto [x, y] : comp) in_comp.insert((1LL * x << 32) | y);

  vector<pair<int, int>> best;
  int best_per = (1 << 30);
  int root = (int)sqrt((double)p);
  for (int h = max(1, root - 3); h <= root + 3; h++) {
    if (h <= 0) continue;
    int w = (p + h - 1) / h;
    for (auto [sx, sy] : comp) {
      vector<pair<int, int>> cur;
      cur.reserve(p);
      bool ok = true;
      for (int i = 0; i < h && (int)cur.size() < p; i++) {
        for (int j = 0; j < w && (int)cur.size() < p; j++) {
          int x = sx + i, y = sy + j;
          long long key = (1LL * x << 32) | y;
          if (!in_grid(x, y) || !in_comp.count(key)) {
            ok = false;
            break;
          }
          cur.emplace_back(x, y);
        }
        if (!ok) break;
      }
      if (!ok || (int)cur.size() != p) continue;
      double c = calc_compactness(cur);
      int per = (int)round(4.0 * sqrt((double)p) / c);
      if (per < best_per) {
        best_per = per;
        best = move(cur);
      }
    }
  }
  return best;
}

Candidate evaluate_region(const vector<pair<int, int>>& region, int p, int v,
                          int duration, const FreeStats& stats) {
  Candidate cand;
  if ((int)region.size() != p) return cand;
  cand.region = region;
  cand.compactness = calc_compactness(region);
  double revenue = llround(v * cand.compactness);
  double unit = (duration > 0 ? revenue / (double)duration : revenue);
  double density = revenue / max(1.0, (double)p);
  double usage = revenue / max(1.0, (double)p * max(1, duration));
  double future = calc_future_bonus(region);

  // 候補評価: 売上 + コンパクト度 + 将来配置性を軽く反映
  cand.score = revenue + 120.0 * cand.compactness + 2.5 * unit +
               20.0 * density + 6.0 * usage + 0.15 * future +
               0.01 * stats.largest_comp;
  cand.ok = true;
  return cand;
}

Candidate find_region_multi(int p, int v, int duration,
                            const FreeStats& stats) {
  Candidate best;
  auto comps = enumerate_components();
  for (auto& comp : comps) {
    if ((int)comp.size() < p) continue;

    vector<pair<int, int>> seeds;
    seeds.push_back(comp[0]);
    int center_idx = rng.next_int(0, (int)comp.size() - 1);
    seeds.push_back(comp[center_idx]);
    int lowx = N, lowy = N;
    for (auto [x, y] : comp) {
      if (x < lowx || (x == lowx && y < lowy)) {
        lowx = x;
        lowy = y;
      }
    }
    seeds.push_back({lowx, lowy});

    for (auto seed : seeds) {
      auto r1 = build_by_bfs(comp, seed, p);
      auto c1 = evaluate_region(r1, p, v, duration, stats);
      if (c1.ok && c1.score > best.score) best = move(c1);

      auto r2 = build_by_dfs(comp, seed, p);
      auto c2 = evaluate_region(r2, p, v, duration, stats);
      if (c2.ok && c2.score > best.score) best = move(c2);

      auto r3 = build_by_growing(comp, seed, p);
      auto c3 = evaluate_region(r3, p, v, duration, stats);
      if (c3.ok && c3.score > best.score) best = move(c3);
    }

    auto r4 = build_by_rectangle(comp, p);
    auto c4 = evaluate_region(r4, p, v, duration, stats);
    if (c4.ok && c4.score > best.score) best = move(c4);
  }
  return best;
}

FreeStats calc_free_stats() {
  FreeStats stats;
  auto comps = enumerate_components();
  stats.comp_count = (int)comps.size();
  for (auto& comp : comps) {
    stats.largest_comp = max(stats.largest_comp, (int)comp.size());
    stats.free_cells += (int)comp.size();
  }
  return stats;
}

void occupy(int id, const vector<pair<int, int>>& region) {
  groups[id].region = region;
  groups[id].compactness = calc_compactness(region);
  for (auto [x, y] : region) {
    owner[x][y] = id;
  }
}

void release(int id) {
  for (auto [x, y] : groups[id].region) {
    owner[x][y] = -1;
  }
  groups[id].region.clear();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M >> R;
  park.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> park[i];
  }
  owner.assign(N, vector<int>(N, -1));
  groups.resize(M);
  long long money = 0;
  for (int i = 0; i < M; i++) {
    int id;
    cin >> id >> groups[id].s >> groups[id].t >> groups[id].p >> groups[id].v;
    while (!leaving.empty() && leaving.top().first < groups[id].s) {
      auto [t, j] = leaving.top();
      leaving.pop();
      money += llround(groups[j].v * groups[j].compactness);
      release(j);
    }

    FreeStats stats = calc_free_stats();

    cout << 0 << '\n';

    int duration = groups[id].t - groups[id].s;
    auto best = find_region_multi(groups[id].p, groups[id].v, duration, stats);

    bool accept = false;
    if (best.ok) {
      double congestion = (stats.free_cells == 0)
                              ? 1.0
                              : 1.0 - (double)stats.free_cells / (N * N);
      double expect = llround(groups[id].v * best.compactness);
      double unit_score = expect / max(1.0, (double)groups[id].p * duration);
      double threshold = 0.07 + 0.25 * congestion;
      if (unit_score >= threshold || expect >= 0.58 * groups[id].v) {
        accept = true;
      }
    }

    if (!accept) {
      cout << "No\n";
    } else {
      occupy(id, best.region);
      leaving.emplace(groups[id].t, id);
      cout << "Yes\n";
      for (auto [x, y] : best.region) {
        cout << x << ' ' << y << '\n';
      }
    }
    cout.flush();
  }
  while (!leaving.empty()) {
    auto [t, j] = leaving.top();
    leaving.pop();
    money += llround(groups[j].v * groups[j].compactness);
    release(j);
  }
  return 0;
}