#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define rrep(i, l, r) for (int i = (r) - 1; i >= (l); i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  map<ll, ll> cnt;
  rep(_, 0, n)
  {
    ll s, c;
    cin >> s >> c;
    cnt[s] += c;
  }
  for (auto it = cnt.begin(); it != cnt.end(); it++)
  {
    ll s = it->first;
    ll c = it->second;
    cnt[s] = c % 2;
    cnt[2 * s] += c / 2;
  }
  ll ans = 0;
  for (auto [_, c] : cnt)
    ans += c;
  cout << ans << endl;
}