#include <bits/stdc++.h>
using namespace std;

struct Op {
  int p, k, d, l;
};

struct Solver {
  int n, K, V;
  vector<string> board;
  vector<int> home;
  vector<vector<int>> st;
  vector<int> floor_cell;
  vector<Op> ans;
  const int dr[4] = {-1, 1, 0, 0};
  const int dc[4] = {0, 0, -1, 1};

  Solver(int n_, int K_, vector<string> board_)
      : n(n_), K(K_), V(n_ * n_), board(move(board_)) {
    home.assign(K, -1);
    floor_cell.assign(V, 0);
    st.resize(V);
    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        int p = r * n + c;
        floor_cell[p] = board[r][c] != '#';
        if ('A' <= board[r][c] && board[r][c] <= 'L')
          home[board[r][c] - 'A'] = p;
        if ('a' <= board[r][c] && board[r][c] <= 'l')
          st[p] = {board[r][c] - 'a' + 1};
      }
    }
  }

  int nxt(int p, int d, int len = 1) const {
    int r = p / n + dr[d] * len;
    int c = p % n + dc[d] * len;
    if (r < 0 || r >= n || c < 0 || c >= n) return -1;
    return r * n + c;
  }

  int direction(int a, int b) const {
    for (int d = 0; d < 4; d++)
      if (nxt(a, d) == b) return d;
    return -1;
  }

  void pop_home(int p) {
    for (int c = 0; c < K; c++) {
      if (home[c] != p) continue;
      while (!st[p].empty() && st[p].back() == c + 1) st[p].pop_back();
      return;
    }
  }

  bool apply(int p, int keep, int d, int len) {
    if (p < 0 || p >= V || st[p].empty() || keep < 0 ||
        keep >= (int)st[p].size())
      return false;
    if (len < 1 || len > keep + 1) return false;
    int q = p;
    for (int x = 1; x <= len; x++) {
      q = nxt(p, d, x);
      if (q < 0 || !floor_cell[q]) return false;
    }
    vector<int> block(st[p].begin() + keep, st[p].end());
    if ((int)st[q].size() + (int)block.size() > 8) return false;
    st[p].resize(keep);
    reverse(block.begin(), block.end());
    st[q].insert(st[q].end(), block.begin(), block.end());
    pop_home(p);
    pop_home(q);
    ans.push_back({p, keep, d, len});
    return true;
  }

  vector<int> route(int s, int g, int color) {
    vector<int> pre(V, -1);
    queue<int> q;
    q.push(s);
    pre[s] = s;
    while (!q.empty()) {
      int p = q.front();
      q.pop();
      if (p == g) break;
      for (int d = 0; d < 4; d++) {
        int v = nxt(p, d);
        if (v < 0 || !floor_cell[v] || pre[v] != -1) continue;
        if (v != g && !st[v].empty()) continue;
        if (v != g && v == home[color]) continue;
        pre[v] = p;
        q.push(v);
      }
    }
    if (pre[g] == -1) return {};
    vector<int> res;
    for (int p = g; p != s; p = pre[p]) res.push_back(p);
    reverse(res.begin(), res.end());
    return res;
  }

  bool move_top(int s, int g, int color) {
    vector<int> path = route(s, g, color);
    if (path.empty()) return false;
    int cur = s;
    for (int v : path) {
      int d = direction(cur, v);
      if (d < 0 || !apply(cur, 0, d, 1)) return false;
      cur = v;
    }
    return true;
  }

  bool try_merge(int s, int g, int color) {
    if (s == g || st[s].empty() || st[g].empty()) return false;
    if (st[s].back() != color + 1 || st[g].back() != color + 1) return false;
    if ((int)st[s].size() + (int)st[g].size() > 8) return false;
    auto old_st = st;
    auto old_ans = ans;
    vector<int> path = route(s, g, color);
    if (path.empty()) return false;
    int cur = s;
    int h = st[s].size();
    for (int v : path) {
      int d = direction(cur, v);
      if (d < 0 || !apply(cur, 0, d, 1)) {
        st = move(old_st);
        ans = move(old_ans);
        return false;
      }
      cur = v;
    }
    if (st[g].size() > 8) {
      st = move(old_st);
      ans = move(old_ans);
      return false;
    }
    return true;
  }

  long long score() const {
    int left = 0;
    for (const auto& s : st) left += s.size();
    return (long long)ans.size() + 100000LL * left;
  }

  void greedy(bool allow_merge, mt19937& rng) {
    for (int iter = 0; iter < 100000; iter++) {
      struct Candidate {
        int s = -1;
        int g = -1;
        int color = -1;
        int type = -1;
        int dist = INT_MAX;
      };
      vector<Candidate> cand;
      for (int color = 0; color < K; color++) {
        for (int s = 0; s < V; s++) {
          if (st[s].empty() || st[s].back() != color + 1 || s == home[color])
            continue;
          auto path = route(s, home[color], color);
          if (!path.empty())
            cand.push_back({s, home[color], color, 0, (int)path.size()});
        }
      }
      if (!cand.empty()) {
        int best = 0;
        for (int i = 1; i < (int)cand.size(); i++) {
          if (cand[i].dist < cand[best].dist)
            best = i;
          else if (cand[i].dist == cand[best].dist && rng() % 2)
            best = i;
        }
        auto c = cand[best];
        move_top(c.s, c.g, c.color);
        continue;
      }
      if (!allow_merge) break;
      vector<Candidate> merges;
      for (int color = 0; color < K; color++) {
        vector<int> p;
        for (int x = 0; x < V; x++) {
          if (!st[x].empty() && st[x].back() == color + 1 && x != home[color])
            p.push_back(x);
        }
        for (int i = 0; i < (int)p.size(); i++) {
          for (int j = 0; j < (int)p.size(); j++) {
            if (i == j) continue;
            if ((int)st[p[i]].size() + (int)st[p[j]].size() > 8) continue;
            auto path = route(p[i], p[j], color);
            if (path.empty()) continue;
            merges.push_back({p[i], p[j], color, 1, (int)path.size()});
          }
        }
      }
      if (merges.empty()) break;
      int best = 0;
      for (int i = 1; i < (int)merges.size(); i++) {
        if (merges[i].dist < merges[best].dist)
          best = i;
        else if (merges[i].dist == merges[best].dist && rng() % 2)
          best = i;
      }
      auto c = merges[best];
      if (!try_merge(c.s, c.g, c.color)) break;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, K;
  cin >> n >> K;
  vector<string> board(n);
  for (auto& s : board) cin >> s;
  mt19937 rng(712367821);
  long long best_score = (1LL << 62);
  vector<Op> best_ans;
  for (int trial = 0; trial < 40; trial++) {
    Solver solver(n, K, board);
    bool allow_merge = trial >= 10;
    solver.greedy(allow_merge, rng);
    long long score = solver.score();
    if (score < best_score) {
      best_score = score;
      best_ans = solver.ans;
    }
  }
  for (auto op : best_ans) {
    cout << op.p / n << ' ' << op.p % n << ' ' << op.k << ' ' << "UDLR"[op.d]
         << ' ' << op.l << '\n';
  }
  return 0;
}
