#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int gcd(int a, int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int gcd3(int a, int b, int c)
{
  return gcd(a, gcd(b, c));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, ans = 0;
  cin >> k;
  rep(a, 1, k + 1) rep(b, 1, k + 1) rep(c, 1, k + 1) ans += gcd3(a, b, c);
  cout << ans << endl;
}