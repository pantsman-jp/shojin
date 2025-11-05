#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> k(n);
  rep(i, 0, n) cin >> k[i];
  ll ans = inf;
  rep(bit, 0, 1 << n)
  {
    ll a = 0, b = 0;
    rep(i, 0, n)
    {
      if (bit & (1 << i))
        a += k[i];
      else
        b += k[i];
    }
    ans = min(ans, max(a, b));
  }
  cout << ans << endl;
}