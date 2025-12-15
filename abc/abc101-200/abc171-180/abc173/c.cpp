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
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> c(h);
  rep(i, 0, h) cin >> c[i];
  int ans = 0;
  rep(bith, 0, 1 << h) rep(bitw, 0, 1 << w)
  {
    int cnt = 0;
    rep(i, 0, h) rep(j, 0, w)
    {
      if ((bith & (1 << i)) == 0 and (bitw & (1 << j)) == 0 and c[i][j] == '#')
        cnt++;
    }
    if (cnt == k)
      ans++;
  }
  cout << ans << endl;
}