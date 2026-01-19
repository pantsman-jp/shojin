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

bool in(ll a, ll b, ll r)
{
  return (2 * a + 1) * (2 * a + 1) + (2 * b + 1) * (2 * b + 1) <= 4 * r * r;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll r;
  cin >> r;
  ll cnt = 0, sup = r - 1;
  for (ll x = 1; in(x, 1, r); x++)
  {
    while (!in(x, sup, r))
      sup--;
    cnt += sup;
  }
  cout << (r - 1) * 4 + 1 + cnt * 4 << endl;
}