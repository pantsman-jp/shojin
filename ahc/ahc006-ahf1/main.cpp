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

struct Order {
  int id;
  int a, b, c, d;
  int dist;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<Order> ord(1000);
  for (int i = 0; i < 1000; i++) {
    cin >> ord[i].a >> ord[i].b >> ord[i].c >> ord[i].d;
    ord[i].id = i + 1;
    ord[i].dist = abs(ord[i].a - ord[i].c) + abs(ord[i].b - ord[i].d);
  }
  sort(all(ord),
       [](const Order& x, const Order& y) { return x.dist < y.dist; });
  vector<int> ans_order;
  vector<pair<int, int>> route;
  route.emplace_back(400, 400);
  for (int i = 0; i < 50; i++) {
    ans_order.push_back(ord[i].id);
    route.emplace_back(ord[i].a, ord[i].b);
    route.emplace_back(ord[i].c, ord[i].d);
  }
  route.emplace_back(400, 400);
  cout << 50;
  for (int x : ans_order) cout << ' ' << x;
  cout << '\n';
  cout << route.size();
  for (auto [x, y] : route) {
    cout << ' ' << x << ' ' << y;
  }
  cout << '\n';
}