// Template: https://github.com/pantsman-jp/shojin/blob/main/awc/template/d.cpp
// License: CC0 1.0 Universal
// https://github.com/pantsman-jp/shojin/blob/main/LICENSE
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<tuple<int, int, ll, ll>> magic;
  rep(_, 0, m) {
    int l, r;
    ll c, w;
    cin >> l >> r >> c >> w;
    magic.emplace_back(l - 1, r - 1, c, w);
  }
  ll ans = INF;
  rep(bit, 0, 1 << m) {
    vector<ll> diff(n + 1);
    ll temp = 0;
    rep(i, 0, m) {
      if ((bit & (1 << i)) != 0) {
        auto [l, r, c, w] = magic[i];
        diff[l] += c;
        diff[r + 1] -= c;
        temp += w;
      }
    }
    rep(i, 0, n) diff[i + 1] += diff[i];
    int cnt = 0;
    rep(i, 0, n) if (a[i] <= diff[i]) cnt++;
    if (cnt == n) chmin(ans, temp);
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}
