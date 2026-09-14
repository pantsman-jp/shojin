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
  int n;
  cin >> n;
  const int m = 2000;
  int sky[m + 2][m + 2], one[m + 2][m + 2];
  vector<array<int, 4>> cloud(n);
  rep(i, 0, n) {
    int u, d, l, r;
    cin >> u >> d >> l >> r;
    u--, d--, l--, r--;
    sky[u][l]++, sky[u][r + 1]--;
    sky[d + 1][l]--, sky[d + 1][r + 1]++;
    cloud[i] = {u, d, l, r};
  }
  rep(i, 0, m) rep(j, 0, m) sky[i + 1][j] += sky[i][j];
  rep(i, 0, m) rep(j, 0, m) sky[i][j + 1] += sky[i][j];
  rep(i, 0, m) rep(j, 0, m) one[i + 1][j + 1] = (sky[i][j] == 1);
  rep(i, 0, m + 1) rep(j, 0, m) one[i][j + 1] += one[i][j];
  rep(i, 0, m) rep(j, 0, m + 1) one[i + 1][j] += one[i][j];
  int base = 0;
  rep(i, 0, m) rep(j, 0, m) if (sky[i][j] == 0) base++;
  rep(i, 0, n) {
    auto [u, d, l, r] = cloud[i];
    cout << base +
                (one[d + 1][r + 1] - one[d + 1][l] - one[u][r + 1] + one[u][l])
         << '\n';
  }
}