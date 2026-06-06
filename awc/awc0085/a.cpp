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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> s(n);
  vector<pii> rest(n);
  rep(i, 0, n) {
    cin >> s[i];
    rest[i] = {s[i], i};
  }
  vector<int> ans(n);
  int r = 1;
  while (rest.size() > 1) {
    vector<pii> next_players;
    for (int i = 0; i < rest.size(); i += 2) {
      pii p1 = rest[i];
      pii p2 = rest[i + 1];
      if (p1.first > p2.first) {
        ans[p2.second] = r;
        next_players.push_back(p1);
      } else {
        ans[p1.second] = r;
        next_players.push_back(p2);
      }
    }
    rest = move(next_players);
    r++;
  }
  rep(i, 0, n) cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}