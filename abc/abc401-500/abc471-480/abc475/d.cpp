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

bool is_prime(ll n) {
  if (n < 2) return false;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> mp(26, -1);
  vector<bool> used(10, false);
  auto dfs = [&](auto self, int idx, ll x) -> bool {
    if (idx == n) {
      if (is_prime(x)) {
        cout << x << '\n';
        return true;
      }
      return false;
    }
    int c = s[idx] - 'a';
    if (mp[c] != -1) {
      return self(self, idx + 1, x * 10 + mp[c]);
    }
    rep(d, 0, 10) {
      if (used[d] or (idx == 0 and d == 0)) continue;
      mp[c] = d;
      used[d] = true;
      if (self(self, idx + 1, x * 10 + d)) return true;
      mp[c] = -1;
      used[d] = false;
    }
    return false;
  };
  if (!dfs(dfs, 0, 0)) cout << -1 << '\n';
}