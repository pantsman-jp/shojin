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
  int n, q;
  cin >> n >> q;
  vector<int> type(q), x(q);
  vector<char> c(q), ans(n, 'a');
  vector<bool> is_put(n);
  rep(i, 0, q) {
    cin >> type[i];
    if (type[i] == 1) {
      cin >> x[i];
      x[i]--;
      is_put[x[i]] = !is_put[x[i]];
    } else {
      cin >> c[i];
    }
  }
  set<int> remain;
  rep(i, 0, n) if (!is_put[i]) remain.insert(i);
  vector<bool> fixed(n);
  rrep(i, 0, q) {
    if (type[i] == 1) {
      if (is_put[x[i]]) {
        if (!fixed[x[i]]) remain.insert(x[i]);
      } else {
        if (!fixed[x[i]]) remain.erase(x[i]);
      }
      is_put[x[i]] = !is_put[x[i]];
    } else {
      for (int x : remain) {
        ans[x] = c[i];
        fixed[x] = true;
      }
      remain.clear();
    }
  }
  rep(i, 0, n) cout << ans[i];
  cout << '\n';
}
