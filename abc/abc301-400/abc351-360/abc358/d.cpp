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
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  multiset<ll> a;
  rep(_, 0, n)
  {
    ll ai;
    cin >> ai;
    a.insert(ai);
  }
  vector<ll> b(m);
  rep(i, 0, m) cin >> b[i];
  sort(all(b));
  ll ans = 0;
  for (ll x : b)
  {
    auto it = a.lower_bound(x);
    if (it == a.end())
    {
      cout << -1 << endl;
      return 0;
    }
    ans += *it;
    a.erase(it);
  }
  cout << ans << endl;
}