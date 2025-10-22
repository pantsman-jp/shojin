#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ll N, R;
  cin >> N >> R;
  vector<int> L(N + 1);
  rep(i, N) cin >> L[i];
  R--;
  ll l = R, r = R;
  rep(i, N)
  {
    if (L[i] == 1)
      continue;
    l = min(l, i - 1);
    r = max(r, i);
  }
  ll ans = 0;
  for (ll i = l + 1; i <= r; i++)
  {
    ans += L[i] + 1;
  }
  cout << ans << endl;
}
