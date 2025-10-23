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
  ll a, b, c;
  cin >> a >> b >> c;
  ll r = gcd(gcd(a, b), c);
  cout << a / r + b / r + c / r - 3 << endl;
}
