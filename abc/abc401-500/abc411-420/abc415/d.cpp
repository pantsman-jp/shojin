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
  ll n;
  int m;
  cin >> n >> m;
  vector<tuple<ll, ll, ll>> c(m);
  rep(i, 0, m)
  {
    ll a, b;
    cin >> a >> b;
    c[i] = {a - b, a, b};
  }
  sort(all(c));
  ll ans = 0;
  for (auto [d, a, b] : c)
  {
    if (n < a)
      continue;
    ll cnt = max(0ll, (n - a) / d + 1);
    ans += cnt;
    n -= d * cnt;
  }
  cout << ans << endl;
}