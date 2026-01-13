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

ll x;
set<ll> ans;

void add(ll d)
{
  ans.insert((d - x / d - 2) / 4);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> x;
  x = 4 * x - 1;
  for (ll d = 1; d * d <= abs(x); d++)
    if (x % d == 0)
      add(d), add(-d), add(x / d), add(-x / d);
  cout << ans.size() << endl;
  for (ll a : ans)
    cout << a << ' ';
  cout << endl;
}