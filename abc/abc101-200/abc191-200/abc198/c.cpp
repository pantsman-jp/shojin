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
  ll r, x, y;
  cin >> r >> x >> y;
  ll d2 = x * x + y * y, ans = 1;
  while (true)
  {
    if (r * r * ans * ans >= d2)
      break;
    ans++;
  }
  if (ans == 1)
  {
    if (r * r != d2)
      ans = 2;
  }
  cout << ans << endl;
}