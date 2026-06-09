#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll m = 1000000007;

struct mat
{
  ll p[2][2] = {{0, 0}, {0, 0}};
};

mat mul(mat a, mat b)
{
  mat ret;
  for (ll i = 0; i < 2; i++)
  {
    for (ll j = 0; j < 2; j++)
    {
      for (ll k = 0; k < 2; k++)
      {
        ret.p[i][j] += (a.p[i][k] * b.p[k][j]) % m;
      }
    }
  }
  return ret;
}

mat pow(mat a, ll n)
{
  mat ret;
  ret.p[0][0] = 1;
  ret.p[1][1] = 1;
  for (ll i = 1; i <= n; i = i << 1)
  {
    if (i & n)
    {
      ret = mul(a, ret);
    }
    a = mul(a, a);
  }
  return ret;
}

int main()
{
  mat a;
  a.p[0][0] = 2;
  a.p[0][1] = 1;
  a.p[1][0] = 1;
  ll n;
  cin >> n;
  a = pow(a, n - 2);
  cout << (a.p[0][0] + a.p[0][1]) % m << endl;
}