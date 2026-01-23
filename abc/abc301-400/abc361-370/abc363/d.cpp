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
  ll n;
  cin >> n;
  if (n == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  n--;
  for (int digit = 1;; digit++)
  {
    ll num = 9;
    rep(i, 0, (digit + 1) / 2 - 1) num *= 10;
    if (n > num)
    {
      n -= num;
      continue;
    }
    n += num / 9 - 1;
    string s = to_string(n);
    string t = s;
    reverse(all(t));
    if (digit % 2 == 1)
      s.pop_back();
    cout << s + t << endl;
    return 0;
  }
}