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
#define dout(x) cout << fixed << setprecision(10) << x << '\n'
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

bool is_leap(int y) {
  if (y % 400 == 0) return true;
  if (y % 100 == 0) return false;
  return y % 4 == 0;
}

int get_days(int y, int m) {
  if (m == 2) {
    return is_leap(y) ? 29 : 28;
  }
  if (m == 4 || m == 6 || m == 9 || m == 11) {
    return 30;
  }
  return 31;
}

string padding(int x, int n, char c) {
  string s = to_string(n);
  return string(max(0, x - (int)s.size()), c) + s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int y = stoi(s.substr(0, 4));
  int m = stoi(s.substr(5, 2));
  int d = stoi(s.substr(8, 2));
  while (true) {
    if (y % (m * d) == 0) {
      break;
    }
    d++;
    if (d > get_days(y, m)) {
      d = 1;
      m++;
      if (m > 12) {
        m = 1;
        y++;
      }
    }
  }
  cout << padding(4, y, '0') << '/' << padding(2, m, '0') << '/'
       << padding(2, d, '0') << '\n';
  return 0;
}