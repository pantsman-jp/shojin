#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, x, y;
  cin >> n >> x >> y;
  rep(a, 1, n + 1)
  {
    rep(b, 1, n + 1)
    {
      rep(c, 1, n + 1)
      {
        ll d = x - a - b - c;
        if (d < 1 or n < d)
          continue;
        if (a * b * c * d == y)
        {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }
  cout << "No" << endl;
}