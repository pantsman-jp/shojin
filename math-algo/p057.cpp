#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll mat2[4][4] = {
    {0, 0, 0, 1},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {1, 0, 0, 1}};

ll mat3[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0}};

ll mat4[16][16] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1}};

struct matrix
{
  int size = 0;
  ll p[16][16];
};

matrix mult(matrix a, matrix b)
{
  matrix c;
  c.size = a.size;
  for (int i = 0; i < a.size; i++)
    for (int j = 0; j < a.size; j++)
      c.p[i][j] = 0;
  for (int i = 0; i < a.size; i++)
    for (int k = 0; k < a.size; k++)
      for (int j = 0; j < a.size; j++)
      {
        c.p[i][j] += (a.p[i][k] * b.p[k][j]) % mod;
        if (c.p[i][j] >= mod)
          c.p[i][j] -= mod;
      }
  return c;
}

matrix mat_pow(matrix base, ll exp)
{
  matrix res;
  res.size = base.size;
  for (int i = 0; i < res.size; i++)
    for (int j = 0; j < res.size; j++)
      res.p[i][j] = (i == j) ? 1 : 0;
  while (exp > 0)
  {
    if (exp & 1LL)
      res = mult(res, base);
    base = mult(base, base);
    exp >>= 1LL;
  }
  return res;
}

int main()
{
  ll k, n;
  if (!(cin >> k >> n))
    return 0;
  matrix a;
  a.size = (1 << k);
  for (int i = 0; i < (1 << k); i++)
    for (int j = 0; j < (1 << k); j++)
      a.p[i][j] = 0;
  for (int i = 0; i < (1 << k); i++)
    for (int j = 0; j < (1 << k); j++)
    {
      if (k == 2)
        a.p[i][j] = mat2[i][j];
      if (k == 3)
        a.p[i][j] = mat3[i][j];
      if (k == 4)
        a.p[i][j] = mat4[i][j];
    }
  matrix b = mat_pow(a, n);
  cout << (b.p[(1 << k) - 1][(1 << k) - 1] % mod) << endl;
}
