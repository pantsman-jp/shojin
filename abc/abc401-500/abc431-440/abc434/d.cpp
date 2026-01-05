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

const int m = 2000;
int sky[m + 2][m + 2];
int one[m + 2][m + 2];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> clouds(n, vector<int>(4));
  rep(i, 0, n)
  {
    int u, d, l, r;
    cin >> u >> d >> l >> r;
    u--, d--, l--, r--;
    sky[u][l]++, sky[u][r + 1]--;
    sky[d + 1][l]--, sky[d + 1][r + 1]++;
    clouds[i] = {u, d, l, r};
  }
  rep(i, 0, m) rep(j, 0, m) sky[i + 1][j] += sky[i][j];
  rep(i, 0, m) rep(j, 0, m) sky[i][j + 1] += sky[i][j];
  rep(i, 0, m) rep(j, 0, m) one[i + 1][j + 1] = (sky[i][j] == 1);
  rep(i, 0, m + 1) rep(j, 0, m) one[i][j + 1] += one[i][j];
  rep(i, 0, m) rep(j, 0, m + 1) one[i + 1][j] += one[i][j];
  int base = 0;
  rep(i, 0, m) rep(j, 0, m) if (sky[i][j] == 0) base++;
  rep(i, 0, n)
  {
    int u = clouds[i][0], d = clouds[i][1], l = clouds[i][2], r = clouds[i][3];
    int ans = base + (one[d + 1][r + 1] - one[d + 1][l] - one[u][r + 1] + one[u][l]);
    cout << ans << endl;
  }
}