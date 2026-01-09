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
  int n;
  cin >> n;
  vector cnt(1001, vector<int>(1001));
  rep(_, 0, n)
  {
    int lx, ly, rx, ry;
    cin >> lx >> ly >> rx >> ry;
    cnt[ly][lx]++, cnt[ly][rx]--;
    cnt[ry][lx]--, cnt[ry][rx]++;
  }
  rep(i, 0, 1001) rep(j, 1, 1001) cnt[i][j] += cnt[i][j - 1];
  rep(i, 1, 1001) rep(j, 0, 1001) cnt[i][j] += cnt[i - 1][j];
  vector<int> ans(n + 1);
  rep(i, 0, 1001) rep(j, 0, 1001) ans[cnt[i][j]]++;
  rep(i, 1, n + 1) cout << ans[i] << endl;
}