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
  ll sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  if ((sx + sy) % 2 == 1)
    sx--;
  if ((tx + ty) % 2 == 1)
    tx--;
  ll x = abs(tx - sx), y = abs(ty - sy), ans = 0;
  if (x < y)
    ans = y;
  else
    ans = (x + y) / 2;
  cout << ans << endl;
}