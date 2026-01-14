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
  vector a(h, vector<ll>(w));
  rep(i, 0, h) rep(j, 0, w) cin >> a[i][j];
  ll ans = 0;
  vector placed(h, vector<bool>(w));
  auto f = [&](auto f, int i, int j, ll x) -> void
  {
    if (j == w)
      j = 0, i++;
    if (i == h)
    {
      chmax(ans, x);
      return;
    }
    if (placed[i][j])
      f(f, i, j + 1, x);
    else
    {
      f(f, i, j + 1, x ^ a[i][j]);
      if (j + 1 < w and !placed[i][j + 1])
      {
        placed[i][j] = placed[i][j + 1] = true;
        f(f, i, j + 1, x);
        placed[i][j] = placed[i][j + 1] = false;
      }
      if (i + 1 < h and !placed[i + 1][j])
      {
        placed[i][j] = placed[i + 1][j] = true;
        f(f, i, j + 1, x);
        placed[i][j] = placed[i + 1][j] = false;
      }
    }
  };
  f(f, 0, 0, 0);
  cout << ans << endl;
}