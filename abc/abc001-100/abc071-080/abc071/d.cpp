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
using mint = modint1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  mint ans = 1;
  int x = 0, prev = -1;
  while (x < n) {
    if (s[x] == t[x]) {
      if (prev < 0)
        ans = 3;
      else if (prev == 0)
        ans *= 2;
      x++, prev = 0;
    } else {
      if (prev < 0)
        ans = 6;
      else if (prev == 0)
        ans *= 2;
      else
        ans *= 3;
      x += 2, prev = 1;
    }
  }
  cout << ans.val() << endl;
  return 0;
}