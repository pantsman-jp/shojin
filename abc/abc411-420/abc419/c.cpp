#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ll n;
  cin >> n;
  ll minR = inf, maxR = -inf;
  ll minC = inf, maxC = -inf;
  rep(_, n)
  {
    ll r, c;
    cin >> r >> c;
    minR = min(minR, r), maxR = max(maxR, r);
    minC = min(minC, c), maxC = max(maxC, c);
  }
  cout << (max(maxR - minR, maxC - minC) + 1) / 2 << endl;
}