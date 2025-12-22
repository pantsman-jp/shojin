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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector f(n, vector(10, 0)), p(n, vector(11, 0));
  rep(i, 0, n) rep(j, 0, 10) cin >> f[i][j];
  rep(i, 0, n) rep(j, 0, 11) cin >> p[i][j];
  int ans = -inf;
  rep(bit, 1, 1 << 10)
  {
    int profit = 0;
    rep(i, 0, n)
    {
      int cnt = 0;
      rep(j, 0, 10) if (f[i][j] == 1 and (bit & (1 << j))) cnt++;
      profit += p[i][cnt];
    }
    chmax(ans, profit);
  }
  cout << ans << endl;
}