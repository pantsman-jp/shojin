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
  int n, r, c;
  string s;
  cin >> n >> r >> c >> s;
  int i = 0, j = 0;
  set<P> smoke;
  smoke.insert({i, j});
  for (char t : s)
  {
    if (t == 'N')
      r++, i++;
    else if (t == 'W')
      c++, j++;
    else if (t == 'S')
      r--, i--;
    else
      c--, j--;
    smoke.insert({i, j});
    if (smoke.find({r, c}) == smoke.end())
      cout << 0;
    else
      cout << 1;
  }
  cout << endl;
}