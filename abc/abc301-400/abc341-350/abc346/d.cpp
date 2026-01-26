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
  int n;
  string s;
  cin >> n >> s;
  vector<ll> c(n);
  rep(i, 0, n) cin >> c[i];
  vector<ll> f0(n + 1), f1(n + 1);
  rep(i, 0, n)
  {
    f0[i + 1] = f0[i];
    f1[i + 1] = f1[i];
    if (i % 2 == 0)
    {
      if (s[i] == '0')
        f1[i + 1] += c[i];
      else
        f0[i + 1] += c[i];
    }
    else
    {
      if (s[i] == '0')
        f0[i + 1] += c[i];
      else
        f1[i + 1] += c[i];
    }
  }
  vector<ll> e0(n + 1), e1(n + 1);
  rrep(i, n, 0)
  {
    e0[i] = e0[i + 1];
    e1[i] = e1[i + 1];
    if (i % 2 == 0)
    {
      if (s[i] == '0')
        e0[i] += c[i];
      else
        e1[i] += c[i];
    }
    else
    {
      if (s[i] == '0')
        e1[i] += c[i];
      else
        e0[i] += c[i];
    }
  }
  ll ans = INF;
  rep(i, 1, n) chmin(ans, min(f0[i] + e0[i], f1[i] + e1[i]));
  cout << ans << endl;
}