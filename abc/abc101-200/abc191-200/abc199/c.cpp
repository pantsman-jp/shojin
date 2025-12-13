#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n, fl = 0;
string s;

void solve()
{
  int t, a, b;
  cin >> t >> a >> b;
  a--, b--;
  if (t == 1)
  {
    if (fl)
      a = (a + n) % (2 * n);
    if (fl)
      b = (b + n) % (2 * n);
    swap(s[a], s[b]);
  }
  else
    fl ^= 1;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> n >> s >> q;
  rep(_, 0, q) solve();
  if (fl)
    s = s.substr(n) + s.substr(0, n);
  cout << s << endl;
}