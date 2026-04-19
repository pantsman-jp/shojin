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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) {
    int n, a, b;
    cin >> n >> a >> b;
    if (n % 2 == 1 or (a + b) % 2 == 0) {
      yn(false);
      continue;
    }
    yn(true);
    string ans = "";
    int i = 1, j = 1, band = (b + 1) / 2;
    rep(k, 1, n / 2 + 1) {
      int c1 = 2 * k - 1, c2 = 2 * k;
      if (k < band) {
        while (i < n) {
          i++;
          ans += 'D';
        }
        ans += 'R';
        j = c2;
        while (i > 1) {
          i--;
          ans += 'U';
        }
        if (k < n / 2) {
          ans += 'R';
          j++;
        }
      } else if (k == band) {
        while (!(i == n and (j == c1 or j == c2))) {
          if (j == c1 and !(i == a and c2 == b)) {
            j = c2;
            ans += 'R';
          } else if (j == c2 and !(i == a and c1 == b)) {
            j = c1;
            ans += 'L';
          }
          if (i < n) {
            i++;
            ans += 'D';
          } else
            break;
        }
        if (j == c1) {
          ans += 'R';
          j = c2;
        }
        if (k < n / 2) {
          ans += 'R';
          j++;
        }
      } else {
        while (i < n) {
          i++;
          ans += 'D';
        }
        ans += 'R';
        j++;
        while (i > 1) {
          i--;
          ans += 'U';
        }
        if (k < n / 2) {
          ans += 'R';
          j++;
        }
      }
    }
    while (i < n) {
      i++;
      ans += 'D';
    }
    while (j < n) {
      j++;
      ans += 'R';
    }
    cout << ans << '\n';
  }
  return 0;
}