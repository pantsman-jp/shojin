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

void solve();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  rep(i, 0, t) solve();
  return 0;
}

void solve() {
  int n, w;
  cin >> n >> w;
  vector<int> x(n), y(n);
  rep(i, 0, n) {
    cin >> x[i] >> y[i];
    x[i]--;
  }
  vector<int> idx(n);
  rep(i, 0, n) idx[i] = i;
  sort(all(idx), [&](int i, int j) { return y[i] < y[j]; });
  vector<int> r(n), num(w);
  for (int i : idx) {
    r[i] = num[x[i]];
    num[x[i]]++;
  }
  vector<int> d(n, inf);
  {
    vector<vector<int>> blocks(n);
    rep(i, 0, n) blocks[r[i]].push_back(i);
    rep(i, 0, n) {
      if (blocks[i].size() != w) continue;
      int mx = 0;
      for (int j : blocks[i]) chmax(mx, y[j] - 1);
      d[i] = mx + 1;
    }
  }
  int q;
  cin >> q;
  rep(_, 0, q) {
    int t, a;
    cin >> t >> a;
    yn(d[r[a - 1]] > t);
  }
}
