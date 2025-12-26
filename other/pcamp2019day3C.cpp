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
  int n, m;
  cin >> n >> m;
  vector a(n, vector<ll>(m));
  rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
  ll ans = -INF;
  rep(t1, 0, m) rep(t2, t1 + 1, m)
  {
    ll tmp = 0;
    rep(i, 0, n) tmp += max(a[i][t1], a[i][t2]);
    chmax(ans, tmp);
  }
  cout << ans << endl;
}