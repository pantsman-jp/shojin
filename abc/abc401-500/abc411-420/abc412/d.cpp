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
  int n, m;
  cin >> n >> m;
  vector g(n, vector<int>(n));
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    g[a][b] = 1, g[b][a] = 1;
  }
  int ans = inf;
  vector<int> p(n);
  rep(i, 0, n) p[i] = i;
  do
  {
    bool ok = true;
    rep(i, 0, n) if (p[i] == i or p[p[i]] == i) ok = false;
    if (ok)
    {
      int cnt = 0;
      rep(i, 0, n) cnt += g[i][p[i]];
      chmin(ans, n + m - cnt * 2);
    }
  } while (next_permutation(all(p)));
  cout << ans << endl;
}