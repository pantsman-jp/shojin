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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
}