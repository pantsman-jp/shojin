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
  int h, w;
  cin >> h >> w;
  vector p(h, vector<int>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> p[i][j];
  int ans = 0;
  rep(bit, 0, 1 << h)
  {
    unordered_map<int, int> cnt;
    rep(j, 0, w)
    {
      int v = -1;
      bool ok = true;
      rep(i, 0, h)
      {
        if ((bit & (1 << i)) != 0)
        {
          if (v == -1)
            v = p[i][j];
          else if (v != p[i][j])
          {
            ok = false;
            break;
          }
        }
      }
      if (ok)
        cnt[v]++;
    }
    int rows = __builtin_popcount(bit);
    for (auto [_, n] : cnt)
      chmax(ans, rows * n);
  }
  cout << ans << endl;
}