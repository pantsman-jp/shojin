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
using mint = modint998244353;
// using mint = modint1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  queue<int> s;
  s.push(1);
  mint ans = 1;
  rep(_, 0, q)
  {
    int t, x;
    cin >> t;
    if (t == 1)
    {
      cin >> x;
      s.push(x);
      ans = ans * 10 + x;
    }
    else if (t == 2)
    {
      int top = s.front();
      s.pop();
      ans -= top * mint(10).pow(s.size());
    }
    else
      cout << ans.val() << endl;
  }
}