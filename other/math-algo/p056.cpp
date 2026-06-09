#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

struct mat
{
  ll p[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
};

mat mul(mat a, mat b)
{
  mat ans;
  for (ll i = 0; i < 3; i++)
  {
    for (ll j = 0; j < 3; j++)
    {
      for (ll k = 0; k < 3; k++)
      {
        ans.p[i][j] = (ans.p[i][j] + a.p[i][k] * b.p[k][j]) % mod;
      }
    }
  }
  return ans;
}

mat mpow(mat a, ll n)
{
  mat ans;
  for (ll i = 0; i < 3; i++)
    ans.p[i][i] = 1;
  while (n > 0)
  {
    if (n & 1)
      ans = mul(ans, a);
    a = mul(a, a);
    n >>= 1;
  }
  return ans;
}

int main()
{
  ll n;
  cin >> n;
  mat a;
  a.p[0][0] = 1, a.p[0][1] = 1, a.p[0][2] = 1;
  a.p[1][0] = 1, a.p[1][1] = 0, a.p[1][2] = 0;
  a.p[2][0] = 0, a.p[2][1] = 1, a.p[2][2] = 0;
  a = mpow(a, n - 3);
  ll ans = (a.p[0][0] * 2 + a.p[0][1] * 1 + a.p[0][2] * 1) % mod;
  cout << ans << endl;
}
