
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

struct Point {
  int x, y;
};

struct Order {
  int id;
  Point start, goal;
  int dist;
};

int manhattan(const Point& a, const Point& b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}

int route_dist(const vector<Order>& ord, const vector<int>& seq) {
  Point cur = {400, 400};
  int total = 0;
  for (int i : seq) {
    total += manhattan(cur, ord[i].start);
    total += manhattan(ord[i].start, ord[i].goal);
    cur = ord[i].goal;
  }
  total += manhattan(cur, {400, 400});
  return total;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int order_count = 1000;
  const int select_count = 50;
  const int iterations = 200000;
  vector<Order> ord(order_count);
  rep(i, 0, order_count) {
    cin >> ord[i].start.x >> ord[i].start.y >> ord[i].goal.x >> ord[i].goal.y;
    ord[i].id = i + 1;
    ord[i].dist = manhattan(ord[i].start, ord[i].goal);
  }
  sort(all(ord),
       [](const Order& a, const Order& b) { return a.dist < b.dist; });
  vector<int> seq(select_count);
  iota(all(seq), 0);
  int cur_dist = route_dist(ord, seq);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  rep(it, 0, iterations) {
    vector<int> cand = seq;
    if (rng() % 2 == 0) {
      int i = rng() % select_count;
      int j = rng() % select_count;
      swap(cand[i], cand[j]);
    } else {
      int i = rng() % select_count;
      int j = rng() % order_count;
      if (find(all(cand), j) != cand.end()) continue;
      cand[i] = j;
    }
    int cand_dist = route_dist(ord, cand);
    if (cand_dist < cur_dist) {
      seq = move(cand);
      cur_dist = cand_dist;
    }
  }
  vector<int> ans_order;
  vector<Point> route;
  route.push_back({400, 400});
  for (int i : seq) {
    ans_order.push_back(ord[i].id);
    route.push_back(ord[i].start);
    route.push_back(ord[i].goal);
  }
  route.push_back({400, 400});
  cout << ans_order.size();
  for (int id : ans_order) cout << ' ' << id;
  cout << '\n';
  cout << route.size();
  for (const Point& p : route) {
    cout << ' ' << p.x << ' ' << p.y;
  }
  cout << '\n';
  return 0;
}
