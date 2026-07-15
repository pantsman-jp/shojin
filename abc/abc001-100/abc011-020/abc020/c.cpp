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

const vector<int> di = {-1, 0, 1, 0};
const vector<int> dj = {0, 1, 0, -1};

bool out(int i, int j, int h, int w) {
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

void solve() {
  int h, w, t;
  cin >> h >> w >> t;
  vector s(h, vector<char>(w));
  int si, sj, gi, gj;
  rep(i, 0, h) rep(j, 0, w) {
    cin >> s[i][j];
    if (s[i][j] == 'S') {
      si = i, sj = j;
    } else if (s[i][j] == 'G') {
      gi = i, gj = j;
    }
  }
  auto check = [&](int x) -> bool {
    rpq<tuple<ll, int, int>> q;
    vector dist(h, vector<ll>(w, INF));
    dist[si][sj] = 0;
    q.push({0, si, sj});
    while (!q.empty()) {
      auto [d, i, j] = q.top();
      q.pop();
      if (d != dist[i][j]) continue;
      rep(k, 0, 4) {
        int ni = i + di[k], nj = j + dj[k];
        if (out(ni, nj, h, w)) continue;
        ll cost = s[ni][nj] == '#' ? x : 1;
        ll nd = d + cost;
        if (nd < dist[ni][nj]) {
          dist[ni][nj] = nd;
          q.push({nd, ni, nj});
        }
      }
    }
    return dist[gi][gj] <= t;
  };
  ll l = 1, r = t + 1;
  while (l <= r) {
    ll mid = l + (r - l) / 2;
    if (check(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << r << '\n';
}