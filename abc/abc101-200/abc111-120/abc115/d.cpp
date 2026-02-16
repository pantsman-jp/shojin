#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(tf) cout << (tf ? "Yes\n" : "No\n")
#define dout(x) cout << fixed << setprecision(10) << x << "\n"
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

ll f(int n, ll x) {
  if (n == 0) return 1;
  ll len = (1LL << (n + 1)) - 3;
  ll num = (1LL << n) - 1;
  if (x == 1) return 0;
  if (x <= len + 1) return f(n - 1, x - 1);
  if (x == len + 2) return num + 1;
  if (x <= (len + 1) * 2) return num + 1 + f(n - 1, x - len - 2);
  return num * 2 + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll x;
  cin >> n >> x;
  cout << f(n, x) << endl;
  return 0;
}