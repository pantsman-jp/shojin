#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod = 998244353;
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector a(n, vector(n, vector<ll>(n)));
  vector sum(n + 1, vector(n + 1, vector<ll>(n + 1)));
  rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) cin >> a[i][j][k];
  rep(i, 1, n + 1) rep(j, 1, n + 1) rep(k, 1, n + 1) sum[i][j][k] = a[i - 1][j - 1][k - 1] + sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1] - sum[i - 1][j - 1][k] - sum[i - 1][j][k - 1] - sum[i][j - 1][k - 1] + sum[i - 1][j - 1][k - 1];
  int q;
  cin >> q;
  rep(_, 0, q)
  {
    int lx, rx, ly, ry, lz, rz;
    cin >> lx >> rx >> ly >> ry >> lz >> rz;
    lx--, ly--, lz--;
    cout << sum[rx][ry][rz] - sum[lx][ry][rz] - sum[rx][ly][rz] - sum[rx][ry][lz] + sum[lx][ly][rz] + sum[lx][ry][lz] + sum[rx][ly][lz] - sum[lx][ly][lz] << endl;
  }
}