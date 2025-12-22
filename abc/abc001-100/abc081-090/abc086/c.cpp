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

int n;
vector<int> t, x, y;

string solve()
{
  int pt = 0, px = 0, py = 0;
  rep(i, 0, n)
  {
    int d = abs(px - x[i]) + abs(py - y[i]), dt = t[i] - pt;
    if (dt < d)
      return "No";
    if ((dt - d) % 2)
      return "No";
    pt = t[i], px = x[i], py = y[i];
  }
  return "Yes";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  t.resize(n), x.resize(n), y.resize(n);
  rep(i, 0, n) cin >> t[i] >> x[i] >> y[i];
  cout << solve() << '\n';
}