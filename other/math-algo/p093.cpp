#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b;
  cin >> a >> b;
  ll g = gcd(a, b);
  __int128 l = (__int128)a / g * b;
  if (l > (__int128)1e18)
    cout << "Large" << endl;
  else
    cout << (ll)l << endl;
}