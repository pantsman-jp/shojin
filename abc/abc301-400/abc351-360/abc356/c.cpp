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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(m);
  vector<bool> r(m);
  rep(i, 0, m)
  {
    int c;
    cin >> c;
    a[i].resize(c);
    rep(j, 0, c)
    {
      cin >> a[i][j];
      a[i][j]--;
    }
    char ri;
    cin >> ri;
    r[i] = (ri == 'o');
  }
  ll ans = 0;
  rep(bit, 0, 1 << n)
  {
    bool ok = true;
    rep(i, 0, m)
    {
      int keys = 0;
      for (int j : a[i])
        if (bit & (1 << j))
          keys++;
      if ((keys < k and r[i]) or (keys >= k and !r[i]))
      {
        ok = false;
        break;
      }
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
}