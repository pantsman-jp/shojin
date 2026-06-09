#include <iostream>
using namespace std;
using ll = long long;

ll N, K;
ll V[20];
ll Answer = 0;

ll GCD(ll A, ll B)
{
  if (B == 0)
    return A;
  return GCD(B, A % B);
}

ll LCM(ll A, ll B)
{
  return (A / GCD(A, B)) * B;
}

int main()
{
  cin >> N >> K;
  for (int i = 1; i <= K; i++)
    cin >> V[i];
  for (int i = 1; i < (1 << K); i++)
  {
    ll cnt = 0;
    ll lcm = 1;
    for (int j = 0; j < K; j++)
    {
      if ((i & (1 << j)) != 0)
      {
        cnt += 1;
        lcm = LCM(lcm, V[j + 1]);
      }
    }
    ll num = N / lcm;
    if (cnt % 2 == 1)
      Answer += num;
    if (cnt % 2 == 0)
      Answer -= num;
  }
  cout << Answer << endl;
}