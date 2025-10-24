#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> b(2 * n + 1);
  b[0] = 0;
  rep(i, 0, n) b[i + 1] = b[i] + a[i];
  rep(i, 0, n) b[i + n + 1] = b[i + n] + a[i];
  if (b[n] % 10 != 0)
  {
    cout << "No" << endl;
    return 0;
  }
  ll target = b[n] / 10;
  rep(i, 0, n + 1)
  {
    ll goal = b[i] + target;
    auto it = lower_bound(b.begin(), b.begin() + 2 * n + 1, goal);
    if (it != b.begin() + 2 * n + 1 and *it == goal)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
