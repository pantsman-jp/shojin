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

bool has_subsequence(string& s, string& t) {
  int pos = 0, n = s.size(), m = t.size();
  rep(i, 0, m) {
    while (pos < n and s[pos] != t[i]) {
      pos++;
    }
    if (pos == n) {
      return false;
    }
    pos++;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<string>> shelves(n);
  rep(i, 0, n) {
    int k;
    cin >> k;
    shelves[i].resize(k);
    rep(j, 0, k) cin >> shelves[i][j];
  }
  int q;
  cin >> q;
  rep(_, 0, q) {
    string t;
    cin >> t;
    int ans = 0;
    for (auto& shelf : shelves) {
      bool hit = false;
      for (auto& title : shelf) {
        if (has_subsequence(title, t)) {
          hit = true;
          break;
        }
      }
      if (hit) ans++;
    }
    cout << ans << '\n';
  }
}