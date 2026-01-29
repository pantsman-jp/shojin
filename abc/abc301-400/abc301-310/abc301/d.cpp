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
using ull = unsigned long long;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
const ld pi = acosl(-1.0L);
// using mint = modint998244353;
// using mint = modint1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  ll n;
  cin >> s >> n;
  int m = s.size();
  ll ans = 0;
  rep(i, 0, m)
  {
    if (s[i] == '1')
      ans += 1LL << (m - i - 1);
    else if (s[i] == '?')
    {
      ll tmp = ans + (1LL << (m - i - 1));
      rep(j, i + 1, m) if (s[j] == '1') tmp += 1LL << (m - j - 1);
      if (tmp <= n)
        ans += 1LL << (m - i - 1);
    }
  }
  if (ans > n)
    ans = -1;
  cout << ans << endl;
}