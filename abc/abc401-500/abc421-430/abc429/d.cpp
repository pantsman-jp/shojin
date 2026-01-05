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
  int n, c;
  ll m;
  cin >> n >> m >> c;
  vector<ll> a(n);
  map<ll, int> cnt;
  rep(i, 0, n) cin >> a[i], cnt[a[i]]++;
  vector<pair<ll, int>> d;
  for (auto p : cnt)
    d.emplace_back(p);
  for (auto [p, q] : cnt)
    d.emplace_back(p + m, q);
  ll px = d[cnt.size() - 1].first - m;
  int r = 0, now = 0;
  ll ans = 0;
  rep(l, 0, cnt.size())
  {
    while (now < c)
      now += d[r].second, r++;
    auto [x, num] = d[l];
    ans += (x - px) * now;
    px = x;
    now -= num;
  }
  cout << ans << endl;
}
