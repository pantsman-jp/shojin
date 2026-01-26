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
  ll a, b, C;
  cin >> a >> b >> C;
  int c = __builtin_popcountll(C);
  if ((a - b + c) % 2 != 0)
  {
    cout << -1 << endl;
    return 0;
  }
  ll p = (a - b + c) / 2;
  ll q = a - p;
  int d = 60 - c;
  if (p < 0 or p > c or q < 0 or q > d)
  {
    cout << -1 << endl;
    return 0;
  }
  ll x = 0, y = 0;
  int pc = 0, qc = 0;
  rep(i, 0, 60)
  {
    if ((C >> i) & 1)
    {
      if (pc < p)
      {
        x |= (1LL << i);
        pc++;
      }
      else
        y |= (1LL << i);
    }
    else if (qc < q)
    {
      x |= (1LL << i);
      y |= (1LL << i);
      qc++;
    }
  }
  cout << x << " " << y << endl;
}