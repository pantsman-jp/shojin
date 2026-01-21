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
  int q;
  cin >> q;
  ll diff = 0;
  queue<ll> pot;
  rep(_, 0, q)
  {
    int n;
    ll t, h;
    cin >> n;
    if (n == 1)
      pot.push(-diff);
    else if (n == 2)
    {
      cin >> t;
      diff += t;
    }
    else
    {
      cin >> h;
      ll ans = 0;
      while (!pot.empty() and pot.front() + diff >= h)
        pot.pop(), ans++;
      cout << ans << endl;
    }
  }
}