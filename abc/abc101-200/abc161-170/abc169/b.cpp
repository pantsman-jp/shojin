#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

const ll sup = 1e18;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ll ans = 1;
  bool ng = false;
  rep(i, 0, n)
  {
    ll a;
    cin >> a;
    if (a == 0)
    {
      cout << 0 << endl;
      return 0;
    }
    if (ng or (sup + 1) / ans < a or ans * a > sup)
      ng = true;
    ans *= a;
  }
  if (ng)
    cout << -1 << endl;
  else
    cout << ans << endl;
}