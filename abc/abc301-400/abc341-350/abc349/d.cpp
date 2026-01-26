#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
const ld pi = acosl(-1.0L);
// const ll mod = 998244353;
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll L, R;
  cin >> L >> R;
  vector<pair<ll, ll>> ans;
  auto f = [&](auto f, ll l, ll r) -> void
  {
    if (L <= l and r <= R)
    {
      ans.emplace_back(l, r);
      return;
    }
    ll mid = (l + r) / 2;
    if (L < mid)
      f(f, l, mid);
    if (mid < R)
      f(f, mid, r);
  };
  f(f, 0, INF);
  cout << ans.size() << endl;
  for (auto [l, r] : ans)
    cout << l << " " << r << endl;
}