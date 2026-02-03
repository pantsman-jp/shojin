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
#define yn(tf) cout << (tf ? "Yes\n" : "No\n");
#define dout(x) cout << fixed << setprecision(10) << x << "\n";
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

int n, n2;
vector<vector<int>> a;
int ans;

void dfs(vector<bool> paired, int x) {
  int si = -1;
  rep(i, 0, n2) if (!paired[i]) {
    si = i;
    break;
  }
  if (si == -1) {
    chmax(ans, x);
    return;
  }
  paired[si] = true;
  rep(i, 0, n2) if (!paired[i] and si != i) {
    paired[i] = true;
    dfs(paired, x ^ a[si][i]);
    paired[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  n2 = 2 * n;
  a = vector<vector<int>>(n2, vector<int>(n2));
  rep(i, 0, n2) rep(j, i + 1, n2) {
    cin >> a[i][j];
    a[j][i] = a[i][j];
  }
  vector<bool> paired(n2);
  dfs(paired, 0);
  cout << ans << endl;
  return 0;
}