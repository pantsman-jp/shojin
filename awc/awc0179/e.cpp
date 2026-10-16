// Template: https://github.com/pantsman-jp/shojin/blob/main/awc/template/e.cpp
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

// Source: https://github.com/pantsman-jp/shojin/blob/main/utils.cpp
vector<int> lis(const vector<int>& a, bool strict = true) {
  vector<int> dp, idx, pre(a.size(), -1);
  rep(i, 0, a.size()) {
    auto it = strict ? lower_bound(all(dp), a[i]) : upper_bound(all(dp), a[i]);
    int j = it - dp.begin();
    if (j > 0) pre[i] = idx[j - 1];
    if (it == dp.end()) {
      dp.push_back(a[i]);
      idx.push_back(i);
    } else {
      *it = a[i];
      idx[j] = i;
    }
  }
  vector<int> ans;
  if (!idx.empty()) {
    for (int i = idx.back(); i != -1; i = pre[i]) {
      ans.push_back(i);
    }
    reverse(all(ans));
  }
  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  cout << n - lis(a, false).size() << '\n';
}
