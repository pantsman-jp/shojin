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
// const ll mod = 1e9 + 7;
const ld pi = acosl(-1.0L);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<ld> angle(n);
  rep(i, 0, n)
  {
    ld x, y;
    cin >> x >> y;
    angle[i] = -atan2(y, x);
  }
  vector<ld> angle2 = angle;
  sort(all(angle2));
  rep(i, 0, n) angle2.push_back(angle2[i] + 2.0 * pi);
  rep(_, 0, q)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    ld start = angle[a], end = angle[b];
    if (end < start)
      end += 2.0 * pi;
    auto it = lower_bound(all(angle2), start - 1e-15L);
    auto l = it;
    auto r = upper_bound(it, it + n, end + 1e-15L);
    cout << distance(l, r) << endl;
  }
}