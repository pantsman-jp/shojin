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
  int n, m;
  cin >> n >> m;
  vector<ll> c(n);
  rep(i, 0, n) cin >> c[i];
  vector<vector<int>> a(m);
  rep(i, 0, m)
  {
    int k;
    cin >> k;
    a[i].resize(k);
    rep(j, 0, k) cin >> a[i][j], a[i][j]--;
  }
  int pow3n = 1;
  rep(i, 0, n) pow3n *= 3;
  ll ans = INF;
  vector<int> x(n);
  rep(bit, 0, pow3n)
  {
    int t = bit;
    rep(i, 0, n) x[i] = t % 3, t /= 3;
    bool ok = true;
    rep(i, 0, m)
    {
      int cnt = 0;
      for (int j : a[i])
        cnt += x[j];
      if (cnt < 2)
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      ll cost = 0;
      rep(i, 0, n) cost += c[i] * x[i];
      chmin(ans, cost);
    }
  }
  cout << ans << endl;
}