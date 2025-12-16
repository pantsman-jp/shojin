#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int d(ll n)
{
  return to_string(n).size();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, x;
  cin >> a >> b >> x;
  ll l = 0, r = 1e9 + 1;
  while (r - l > 1)
  {
    ll mid = (l + r) / 2;
    if (a * mid + b * d(mid) > x)
      r = mid;
    else
      l = mid;
  }
  cout << l << endl;
}