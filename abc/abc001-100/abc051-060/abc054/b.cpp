#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, m) cin >> b[i];
  rep(ia, 0, n - m + 1) rep(ja, 0, n - m + 1)
  {
    bool ok = true;
    rep(ib, 0, m) rep(jb, 0, m)
    {
      if (a[ia + ib][ja + jb] != b[ib][jb])
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}