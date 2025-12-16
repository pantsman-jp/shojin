#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
  return a / gcd(a, b) * b;
}

ll count(ll a, ll b, ll mod)
{
  return b / mod - (a - 1) / mod;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (b - a + 1) - (count(a, b, c) + count(a, b, d) - count(a, b, lcm(c, d))) << endl;
}