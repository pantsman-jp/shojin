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
  vector<int> s(n);
  rep(i, 0, n) cin >> s[i];
  int ans = -inf;
  rep(i, 0, n)
  {
    P best = {-inf, -1};
    rep(j, 0, n)
    {
      if (i == j)
        continue;
      int aoki = 0;
      int l = min(i, j), r = max(i, j);
      rep(k, l, r + 1) if ((k - l) % 2 == 1) aoki += s[k];
      best = max(best, P(aoki, -j));
    }
    int j = -best.second;
    int l = min(i, j), r = max(i, j);
    int takahashi = 0;
    rep(k, l, r + 1)
    {
      if ((k - l) % 2 == 0)
        takahashi += s[k];
    }
    chmax(ans, takahashi);
  }
  cout << ans << endl;
}