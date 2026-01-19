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
  int n, q;
  cin >> n >> q;
  vector<int> p2b(n), b2h(n), h2b(n);
  rep(i, 0, n) p2b[i] = i, b2h[i] = i, h2b[i] = i;
  rep(_, 0, q)
  {
    int t, a, b;
    cin >> t;
    if (t == 1)
    {
      cin >> a >> b;
      a--, b--;
      p2b[a] = h2b[b];
    }
    else if (t == 2)
    {
      cin >> a >> b;
      a--, b--;
      swap(h2b[a], h2b[b]);
      b2h[h2b[a]] = a;
      b2h[h2b[b]] = b;
    }
    else
    {
      cin >> a;
      a--;
      cout << b2h[p2b[a]] + 1 << endl;
    }
  }
}