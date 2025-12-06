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
  ll x, a, d, n;
  cin >> x >> a >> d >> n;
  if (d == 0)
  {
    cout << abs(a - x) << endl;
    return 0;
  }
  if (d < 0)
    a = a + d * (n - 1), d = -d;
  ll i = (x - a) / d;
  auto f = [&](ll i)
  {
    if (i < 0)
      i = 0;
    if (i >= n)
      i = n - 1;
    return a + d * i;
  };
  cout << min(abs(f(i) - x), abs(f(i + 1) - x)) << endl;
}