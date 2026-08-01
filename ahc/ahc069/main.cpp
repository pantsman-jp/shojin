#include <bits/stdc++.h>
using namespace std;

static const int MAX_N = 50;
static const int DX[4] = {-1, 1, 0, 0};
static const int DY[4] = {0, 0, -1, 1};

int N, M;
double R;
char field[MAX_N][MAX_N];
int owner[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool in_region[MAX_N][MAX_N];
int total_lawn = 0;

struct Group {
  int id = -1;
  int S = 0;
  int T = 0;
  int P = 0;
  long long V = 0;
  bool accepted = false;
  double compactness = 0.0;
  vector<pair<int, int>> cells;
};

struct Component {
  vector<pair<int, int>> cells;
  vector<vector<bool>> in_component;
};

vector<Group> groups;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    leave_queue;
long long money = 0;

bool canUse(int x, int y) {
  return 0 <= x && x < N && 0 <= y && y < N && field[x][y] == '.' &&
         owner[x][y] == -1;
}

int countFreeCells() {
  int free_cells = 0;
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (canUse(x, y)) {
        ++free_cells;
      }
    }
  }
  return free_cells;
}

vector<Component> enumerateComponents() {
  vector<Component> components;
  queue<pair<int, int>> q;

  memset(visited, 0, sizeof(visited));

  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      if (!canUse(x, y) || visited[x][y]) {
        continue;
      }

      Component component;
      component.in_component.assign(N, vector<bool>(N, false));
      visited[x][y] = true;
      q.emplace(x, y);
      component.in_component[x][y] = true;

      while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        component.cells.emplace_back(cx, cy);

        for (int dir = 0; dir < 4; ++dir) {
          int nx = cx + DX[dir];
          int ny = cy + DY[dir];
          if (0 <= nx && nx < N && 0 <= ny && ny < N && canUse(nx, ny) &&
              !visited[nx][ny]) {
            visited[nx][ny] = true;
            component.in_component[nx][ny] = true;
            q.emplace(nx, ny);
          }
        }
      }

      components.push_back(move(component));
    }
  }

  return components;
}

double calcCompact(const vector<pair<int, int>>& cells) {
  memset(in_region, 0, sizeof(in_region));
  for (const auto& cell : cells) {
    in_region[cell.first][cell.second] = true;
  }

  int perimeter = 0;
  for (const auto& cell : cells) {
    int x = cell.first;
    int y = cell.second;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + DX[dir];
      int ny = y + DY[dir];
      if (nx < 0 || nx >= N || ny < 0 || ny >= N || !in_region[nx][ny]) {
        ++perimeter;
      }
    }
  }

  if (perimeter == 0) {
    return 0.0;
  }
  return 4.0 * sqrt(static_cast<double>(cells.size())) /
         static_cast<double>(perimeter);
}

long long calcFee(long long V, double compactness) {
  return static_cast<long long>(
      floor(static_cast<long double>(V) * compactness + 0.5L));
}

const vector<array<int, 4>>& getDirectionOrders() {
  static vector<array<int, 4>> orders = []() {
    vector<array<int, 4>> result;
    array<int, 4> order = {0, 1, 2, 3};
    do {
      result.push_back(order);
    } while (next_permutation(order.begin(), order.end()));
    if (result.size() > 8) {
      result.resize(8);
    }
    return result;
  }();
  return orders;
}

vector<pair<int, int>> bfsOnComponent(const vector<vector<bool>>& in_component,
                                      int start_x, int start_y, int target_size,
                                      const array<int, 4>& order) {
  memset(visited, 0, sizeof(visited));
  queue<pair<int, int>> q;
  vector<pair<int, int>> region;
  region.reserve(150);

  visited[start_x][start_y] = true;
  q.emplace(start_x, start_y);

  while (!q.empty() && static_cast<int>(region.size()) < target_size) {
    auto [x, y] = q.front();
    q.pop();
    region.emplace_back(x, y);

    for (int dir = 0; dir < 4; ++dir) {
      int ndir = order[dir];
      int nx = x + DX[ndir];
      int ny = y + DY[ndir];
      if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny] &&
          in_component[nx][ny]) {
        visited[nx][ny] = true;
        q.emplace(nx, ny);
      }
    }
  }

  if (static_cast<int>(region.size()) < target_size) {
    return {};
  }
  region.resize(target_size);
  return region;
}

struct Candidate {
  vector<pair<int, int>> cells;
  double compactness = 0.0;
  long double density = -1.0;
};

Candidate findBestRegion(const Group& group, int free_cells,
                         const vector<Component>& components) {
  Candidate best;
  const auto& orders = getDirectionOrders();
  int duration = max(1, group.T - group.S);

  long double free_ratio = 0.0L;
  if (total_lawn > 0) {
    free_ratio = static_cast<long double>(free_cells) /
                 static_cast<long double>(total_lawn);
  }

  long double threshold = 0.8L;
  if (free_ratio > 0.70L) {
    threshold = 0.5L;
  } else if (free_ratio < 0.20L) {
    threshold = 1.2L;
  }

  for (const Component& component : components) {
    if (static_cast<int>(component.cells.size()) < group.P) {
      continue;
    }

    int start_limit = min<int>(3, component.cells.size());
    for (int start_index = 0; start_index < start_limit; ++start_index) {
      const auto [sx, sy] = component.cells[start_index];
      for (const auto& order : orders) {
        vector<pair<int, int>> region =
            bfsOnComponent(component.in_component, sx, sy, group.P, order);
        if (region.empty()) {
          continue;
        }

        double compactness = calcCompact(region);
        long long fee = calcFee(group.V, compactness);
        long double density = static_cast<long double>(fee) /
                              (static_cast<long double>(group.P) *
                               static_cast<long double>(duration));

        if (density > best.density) {
          best.cells = move(region);
          best.compactness = compactness;
          best.density = density;
        }
      }
    }
  }

  if (best.density < threshold) {
    return {};
  }
  return best;
}

void placeGroup(Group& group, const vector<pair<int, int>>& cells) {
  group.cells = cells;
  group.compactness = calcCompact(cells);
  group.accepted = true;
  for (const auto& cell : cells) {
    owner[cell.first][cell.second] = group.id;
  }
  leave_queue.emplace(group.T, group.id);
}

void removeGroup(int id) {
  Group& group = groups[id];
  if (!group.accepted) {
    return;
  }

  for (const auto& cell : group.cells) {
    owner[cell.first][cell.second] = -1;
  }
  money += calcFee(group.V, group.compactness);
  group.cells.clear();
  group.accepted = false;
}

void processLeaves(int now) {
  while (!leave_queue.empty() && leave_queue.top().first <= now) {
    int id = leave_queue.top().second;
    leave_queue.pop();
    removeGroup(id);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n_input, m_input;
  cin >> n_input >> m_input >> R;
  N = n_input;
  M = m_input;
  for (int x = 0; x < N; ++x) {
    string row;
    cin >> row;
    for (int y = 0; y < N; ++y) {
      field[x][y] = row[y];
      owner[x][y] = -1;
      if (field[x][y] == '.') {
        ++total_lawn;
      }
    }
  }

  groups.resize(M);

  for (int i = 0; i < M; ++i) {
    int input_id, s, t, p;
    long long v;
    cin >> input_id >> s >> t >> p >> v;

    Group group;
    group.id = input_id;
    group.S = s;
    group.T = t;
    group.P = p;
    group.V = v;
    groups[input_id] = group;

    processLeaves(s);

    vector<Component> components = enumerateComponents();

    cout << 0 << '\n';

    int free_cells = countFreeCells();
    Candidate candidate =
        findBestRegion(groups[input_id], free_cells, components);
    if (candidate.cells.empty()) {
      cout << "No" << '\n';
    } else {
      placeGroup(groups[input_id], candidate.cells);
      cout << "Yes" << '\n';
      for (const auto& cell : candidate.cells) {
        cout << cell.first << ' ' << cell.second << '\n';
      }
    }

    cout.flush();
  }

  return 0;
}
