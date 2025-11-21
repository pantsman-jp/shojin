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
  vector<ll> ans;
  rep(bit, 0, 1 << 10)
  {
    ll x = 0;
    for (int i = 9; i >= 0; --i)
      if (bit & (1 << i))
        x = x * 10 + i;
    if (x > 0)
      ans.push_back(x);
  }
  sort(all(ans));
  ll k;
  cin >> k;
  cout << ans[k - 1] << endl;
}