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
// const ll mod =;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector c(3, vector<int>(3));
  rep(i, 0, 3) rep(j, 0, 3) cin >> c[i][j];
  bool ok = true;
  rep(i, 0, 3) if (c[i][0] - c[i][1] != c[0][0] - c[0][1]) ok = false;
  rep(i, 0, 3) if (c[i][1] - c[i][2] != c[0][1] - c[0][2]) ok = false;
  yn(ok)
}