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
  ll x, k, d;
  cin >> x >> k >> d;
  x = abs(x);
  ll q = x / d, r = x % d, ans;
  if (q >= k)
    ans = x - d * k;
  else if ((k - q) % 2 == 0)
    ans = r;
  else
    ans = d - r;
  cout << ans << endl;
}