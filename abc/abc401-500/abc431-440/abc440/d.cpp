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

ll n, q;
vector<ll> a;

void solve()
{
  ll x, y;
  cin >> x >> y;
  ll left = x, right = x + y + n;
  ll i = lower_bound(all(a), x) - a.begin();
  while (left < right)
  {
    ll mid = (left + right) / 2;
    ll cnt = (mid - x + 1) - (lower_bound(all(a), mid + 1) - a.begin() - i);
    if (cnt >= y)
      right = mid;
    else
      left = mid + 1;
  }
  cout << left << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  rep(_, 0, q) solve();
}