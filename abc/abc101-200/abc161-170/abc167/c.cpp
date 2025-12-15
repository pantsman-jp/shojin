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
  int n, m, x;
  cin >> n >> m >> x;
  vector<int> c(n);
  vector a(n, vector<int>(m));
  rep(i, 0, n)
  {
    cin >> c[i];
    rep(j, 0, m) cin >> a[i][j];
  }
  int ans = 1e9;
  rep(bit, 0, 1 << n)
  {
    int cst = 0;
    vector<int> rikai(m);
    rep(i, 0, n)
    {
      if (bit & (1 << i))
      {
        cst += c[i];
        rep(j, 0, m) rikai[j] += a[i][j];
      }
    }
    bool ok = true;
    rep(i, 0, m) if (rikai[i] < x) ok = false;
    if (ok)
      ans = min(ans, cst);
  }
  if (ans == 1e9)
    ans = -1;
  cout << ans << endl;
}