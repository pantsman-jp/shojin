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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, n;
  cin >> a >> b >> n;
  ll lcm = a * b / gcd(a, b);
  cout << (n + lcm - 1) / lcm * lcm << endl;
}