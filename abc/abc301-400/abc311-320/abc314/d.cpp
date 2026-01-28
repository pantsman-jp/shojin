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
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<int> lt(n);
  int last = -1, type = 2;
  rep(i, 0, q)
  {
    int t, x;
    char c;
    cin >> t >> x >> c;
    x--;
    if (t == 1)
    {
      s[x] = c;
      lt[x] = i;
    }
    else
    {
      last = i;
      type = t;
    }
  }
  rep(i, 0, n) if (lt[i] < last)
  {
    if (type == 2)
      s[i] = tolower(s[i]);
    else
      s[i] = toupper(s[i]);
  }
  cout << s << endl;
}