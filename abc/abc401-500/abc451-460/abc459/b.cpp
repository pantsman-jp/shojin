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

int solve(char c) {
  if (c == 'a' or c == 'b' or c == 'c') return 2;
  if (c == 'd' or c == 'e' or c == 'f') return 3;
  if (c == 'g' or c == 'h' or c == 'i') return 4;
  if (c == 'j' or c == 'k' or c == 'l') return 5;
  if (c == 'm' or c == 'n' or c == 'o') return 6;
  if (c == 'p' or c == 'q' or c == 'r' or c == 's') return 7;
  if (c == 't' or c == 'u' or c == 'v') return 8;
  if (c == 'w' or c == 'x' or c == 'y' or c == 'z') return 9;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  rep(_, 0, n) {
    string s;
    cin >> s;
    cout << solve(s[0]);
  }
  cout << '\n';
  return 0;
}