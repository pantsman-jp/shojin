#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int n;
  cin >> n;
  ll ans = inf;
  rep(_, n)
  {
    int a;
    cin >> a;
    ll cnt = 0;
    while (a % 2 == 0)
      a /= 2, cnt++;
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}