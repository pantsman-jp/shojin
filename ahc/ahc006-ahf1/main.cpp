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
// using mint = modint998244353;
// using mint = modint1000000007;

struct Point {
  int x, y;
};

struct Order {
  int id;
  Point start, goal;
  int dist;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  const int order_count = 1000;
  vector<Order> ord(order_count);
  rep(i, 0, order_count) {
    cin >> ord[i].start.x >> ord[i].start.y >> ord[i].goal.x >> ord[i].goal.y;
    ord[i].id = i + 1;
    ord[i].dist = abs(ord[i].start.x - ord[i].goal.x) +
                  abs(ord[i].start.y - ord[i].goal.y);
  }
  sort(all(ord),
       [](const Order& a, const Order& b) { return a.dist < b.dist; });
  vector<int> ans_order;
  vector<Point> route;
  route.push_back({400, 400});
  rep(i, 0, 50) {
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
