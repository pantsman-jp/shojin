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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  rep(i, 1, n + 1) cin >> a[i];
  vector<int> x(n + 1);
  rrep(i, 1, n + 1) {
    int sum = 0;
    for (int j = 2 * i; j <= n; j += i) sum ^= x[j];
    x[i] = sum ^ a[i];
  }
  vector<int> ans;
  rep(i, 1, n + 1) if (x[i] == 1) ans.push_back(i);
  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";
  cout << endl;
  return 0;
}