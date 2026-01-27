#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

int count(vector<int> p)
{
  int cnt = 0;
  rep(i, 0, p.size()) rep(j, i + 1, p.size()) if (p[i] > p[j]) cnt++;
  return cnt;
}

int main()
{
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w)), b(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  rep(i, 0, h) rep(j, 0, w) cin >> b[i][j];
  vector<int> row(h), line(w);
  iota(all(row), 0);
  iota(all(line), 0);
  int ans = inf;
  do
  {
    do
    {
      bool ok = true;
      for (int i = 0; i < h and ok; i++)
        for (int j = 0; j < w and ok; j++)
          if (a[row[i]][line[j]] != b[i][j])
            ok = false;
      if (ok)
        chmin(ans, count(row) + count(line));
    } while (next_permutation(all(line)));
  } while (next_permutation(all(row)));
  if (ans == inf)
    cout << -1 << endl;
  else
    cout << ans << endl;
}