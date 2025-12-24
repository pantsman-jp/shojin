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
  vector<ll> a(n);
  ll mn = INF, mx = -INF;
  rep(i, 0, n) cin >> a[i], chmin(mn, a[i]), chmax(mx, a[i]);
  ll ans = INF;
  rep(i, mn, mx + 1)
  {
    ll tmp = 0;
    rep(j, 0, n) tmp += (a[j] - i) * (a[j] - i);
    chmin(ans, tmp);
  }
  cout << ans << endl;
}