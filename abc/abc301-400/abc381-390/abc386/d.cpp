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
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, char>> pts;
  rep(i, 0, m)
  {
    int x, y;
    char c;
    cin >> x >> y >> c;
    pts.emplace_back(x, y, c);
  }
  sort(rall(pts));
  int maxy = -1;
  for (auto [x, y, c] : pts)
  {
    if (c == 'B')
      chmax(maxy, y);
    else
    {
      if (y <= maxy)
      {
        yn(false);
        return 0;
      }
    }
  }
  yn(true);
}