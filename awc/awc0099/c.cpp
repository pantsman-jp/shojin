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
inline T ceildiv(T a, T b) {
  return (a + b - 1) / b;
}
template <typename T>
using vc = vector<T>;
template <typename T>
using pq = priority_queue<T>;
template <typename T>
using rpq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
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
  int N, Q;
  cin >> N >> Q;
  vector<vector<int>> g(N);
  rep(i, 1, N) {
    int p;
    cin >> p;
    g[p - 1].push_back(i);
  }
  vector<int> in(N), out(N), ord;
  auto dfs = [&](auto self, int v) -> void {
    in[v] = ord.size();
    ord.push_back(v);
    for (int to : g[v]) self(self, to);
    out[v] = ord.size();
  };
  dfs(dfs, 0);
  vector<ll> diff(N + 1);
  rep(i, 0, Q) {
    int x;
    ll d;
    cin >> x >> d;
    x--;
    diff[in[x]] += d;
    diff[out[x]] -= d;
  }
  rep(i, 1, N) diff[i] += diff[i - 1];
  vector<ll> ans(N);
  rep(i, 0, N) ans[ord[i]] = diff[i];
  for (ll x : ans) cout << x << ' ';
  cout << '\n';
}