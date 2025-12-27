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
  int n;
  cin >> n;
  vector<pair<ll, ll>> pts(n);
  rep(i, 0, n) cin >> pts[i].first >> pts[i].second;
  unordered_set<ll> S;
  S.reserve(n * 2);
  const ll sup = 5001;
  for (auto [x, y] : pts)
    S.insert(x * sup + y);
  ll ans = 0;
  rep(i, 0, n) rep(j, i + 1, n)
  {
    ll x1 = pts[i].first, y1 = pts[i].second;
    ll x2 = pts[j].first, y2 = pts[j].second;
    ll dx = x2 - x1, dy = y2 - y1;
    ll area = dx * dx + dy * dy;
    if (area <= ans)
      continue;
    ll px1 = x1 - dy, py1 = y1 + dx;
    ll px2 = x2 - dy, py2 = y2 + dx;
    ll key1 = px1 * sup + py1, key2 = px2 * sup + py2;
    if (S.count(key1) and S.count(key2))
    {
      ans = area;
      continue;
    }
    px1 = x1 + dy, py1 = y1 - dx;
    px2 = x2 + dy, py2 = y2 - dx;
    key1 = px1 * sup + py1, key2 = px2 * sup + py2;
    if (S.count(key1) and S.count(key2))
      ans = area;
  }
  cout << ans << endl;
}