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
// const ll mod = 1e9 + 7;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> deg(n);
  rep(_, 0, m)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++, deg[b]++;
  }
  rep(i, 0, n)
  {
    ll cnt = n - 1 - deg[i];
    if (cnt < 3)
      cout << 0;
    else
      cout << cnt * (cnt - 1) * (cnt - 2) / 6;
    cout << " ";
  }
  cout << endl;
}