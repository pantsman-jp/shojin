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

string xxize(const string& s) {
  string ret;
  for (char c : s) {
    ret.push_back(c);
    while (ret.size() >= 4) {
      int n = ret.size();
      if (ret[n - 4] == '(' and ret[n - 3] == 'x' and ret[n - 2] == 'x' and
          ret[n - 1] == ')') {
        rep(_, 0, 4) ret.pop_back();
        rep(_, 0, 2) ret.push_back('x');
      } else {
        break;
      }
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) {
    string a, b;
    cin >> a >> b;
    yn(xxize(a) == xxize(b));
  }
  return 0;
}