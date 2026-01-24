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
const ll mod = 998244353;
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  n++;
  ll ans = 0;
  rep(i, 0, 60)
  {
    if (((m >> i) & 1) != 0)
    {
      ll cycle = 1LL << (i + 1);
      ll count = (n / cycle % mod) * ((1LL << i) % mod) % mod;
      ll rem = n % cycle;
      if (rem > (1LL << i))
        count = (count + (rem - (1LL << i))) % mod;
      ans = (ans + count) % mod;
    }
  }
  cout << ans << endl;
}