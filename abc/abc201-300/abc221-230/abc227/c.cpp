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
  ll n, ans = 0;
  cin >> n;
  for (ll a = 1; a * a * a <= n; a++)
  {
    for (ll b = a; a * b * b <= n; b++)
    {
      ll m = n / (a * b);
      if (m >= b)
        ans += m - b + 1;
    }
  }
  cout << ans << endl;
}