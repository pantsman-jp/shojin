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
  int m;
  cin >> m;
  vector<int> x1(m), y1(m);
  rep(i, 0, m) cin >> x1[i] >> y1[i];
  int n;
  cin >> n;
  vector<int> x2(n), y2(n);
  rep(i, 0, n) cin >> x2[i] >> y2[i];
  set<P> stars;
  rep(i, 0, n) stars.insert({x2[i], y2[i]});
  int ansx, ansy;
  rep(i, 0, n)
  {
    int dx = x2[i] - x1[0], dy = y2[i] - y1[0];
    bool ok = true;
    rep(j, 0, m) if (stars.count({x1[j] + dx, y1[j] + dy}) == 0) ok = false;
    if (ok)
      ansx = dx, ansy = dy;
  }
  cout << ansx << ' ' << ansy << endl;
}