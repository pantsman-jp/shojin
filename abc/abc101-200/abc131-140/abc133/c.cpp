#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll l, r, ans = inf;
  cin >> l >> r;
  rep(i, l, r) rep(j, i + 1, r + 1)
  {
    ans = min(ans, (i * j) % 2019);
    if (ans == 0)
    {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}